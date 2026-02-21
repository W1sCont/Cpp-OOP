#pragma once

#include "exam_order.h"
#include "exam_product.h"
#include <iomanip>

using std::cin;
using std::cout;
using std::endl;
using std::string;

#include <string>
#include <iostream>

class showApp {
private:
    Order<Product> cart;
    Customers* currentUser;
    void registration();
    void mainLoop();
    void addItem();
    void removeItem();
    void clearOrder();
    void exitAndSave();
    void showProductMenu();
public:
    showApp() : cart{10}, currentUser{ nullptr } {}
    ~showApp() { delete currentUser; }

    void run() {
        registration();
        mainLoop();
    }
};