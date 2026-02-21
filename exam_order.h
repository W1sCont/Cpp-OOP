#pragma once

#include <iostream>
#include <fstream>
#include <vector>
#include <memory>
#include <iomanip>

#include "exam_product.h"

using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::setw;

class Customers;

template <typename T>
class Order {
protected:
    std::shared_ptr<vector<T*>> items;
public:
    explicit Order(int cap_) : items{std::make_shared<vector<T*>>()} { items->reserve(cap_); }

    void add(T* item_) {
        if (item_ == nullptr) return;
        for (const auto& item : *items) {
            if (item->getName() == item_->getName()) {
                item->countPP();
                delete item_;
                return;
            }
        }
        items->push_back(item_);
    }

    void remove(int idx_) {
        if (idx_ > items->size() || idx_ < 0 ) return;
        if ((*items)[idx_]->getCount() != 1) {
            (*items)[idx_]->countMM();
            return;
        }
        delete (*items)[idx_];
        items->erase(items->begin() + idx_);
    }

    int getSize() const { return items->size(); }

    void clear() {
        for (auto item : *items) delete item;
        items->clear();
    }

    void process(const Customers& customer) const {
        double total{0};
        cout << "\n============================= Processing order =====================================================\n";
        cout << "   ORDER FOR: " << customer.getName();
        if (customer.getVIP()) cout << " [VIP MEMBER]";
        cout << "\n====================================================================================================\n";
        //
        cout << "| " << std::left << setw(10) << "ITEM"
            << " | " << setw(20) << "NAME"
            << " | " << setw(10) << "SPEC"
            << " | " << setw(7)  << "PRICE"
            << " | " << setw(5)  << "QTY"
            << " | " << setw(8)  << "TOTAL" << " |\n";
        //

        for (const auto& item : *items ) {
            item->info();
            total += item->getTotalPrice();
        }
        cout << "\n====================================================================================================\n";
        cout << "Subtotal: " << total << " usd\n\n";

        if (customer.getVIP() && total > 0) {
            double discount = total * 0.10; // 10%
            total -= discount;
            cout << "VIP Discount (10%): -" << discount << " usd" << endl;
        }

        cout << "Total to pay: " << total << " usd" << endl;
        cout << "\n====================================================================================================\n";
    }

    void saveToFile(string filename, const Customers& customer) const {
        std::ofstream file(filename);
        if (file.is_open()) {
            file << customer.toFileStr() << endl;

            for (const auto& item : *items) {
                file << item->toFileStr() << endl;
            }
            file.close();
            std::cout << "Your cart save to " << filename << endl;
        }
    }
};