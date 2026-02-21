#include "exam_showApp.h"
#include "exam_product.h"
#include "exam_order.h"
#include <iomanip>

void showApp::registration() {
    cout << "======================== Welcome to E-Shop Registration ============================================\n";
    cout << "Enter your name: ";
    string userName;
    getline(cin, userName);

    cout << "Are you a VIP member? (1 - Yes, 0 - No): ";
    bool vipStatus = (choiceInput() == 1);

    currentUser = new Customers(userName, vipStatus);
}

void showApp::mainLoop() {
    bool isContinue = true;
    while (isContinue) {
        cart.process(*currentUser);
        cout << "1-Add | 2-Remove | 3-Clear order | 0-Save & Exit: \n > ";
        int choice = choiceInput();

        switch (choice) {
            case 1: addItem(); break;
            case 2: removeItem(); break;
            case 3: clearOrder(); break;
            case 0: exitAndSave(); isContinue = false; break;
            default: cout << "Unknown command!\n";
        }
    }
}

void showApp::showProductMenu() {
    cout << "| " << std::left << setw(30) << "1-Add Banana Type: Cavendish"
        << " | " << setw(30) << "2-Add Banana Type: Blue Java"
        << " | " << setw(30) << "3-Add Milk Type: Galychyna"
        << " |\n"
        << "| " << setw(30) << "4-Add Bread Type: Baguette"
        << " | " << setw(30) << "5-Add Apple juice 80%"
        << " | " << setw(30) << "6-Add Laptop MacBook M3"
        << " |\n"
        << "| " << setw(30) << "7-Add Headphones Sony XM5"
        << " | " << setw(30) << "8-Add SmartWatch Apple Watch 9"
        << " | " << setw(30) << "9-Add Tablet iPad Air"
        << " |\n"
        << "| " << setw(30) << "10-Add Iphone 15 RAM 8"
        << " | " << setw(30) << "11-Add Iphone 15 RAM 16"
        << " | " << setw(30) << "0-Exit"
        << " |\n > ";
}

void showApp::addItem() {
    while (true) {
        cart.process(*currentUser);
        showProductMenu();
        int idx = choiceInput();
        if (idx == 0) break;
        if (idx) cart.add(productFactory::createFactory(idx));
    }
}

void showApp::removeItem() {
    if (cart.getSize() > 0) {
        cout << "Enter order number to remove: ";
        cart.remove(choiceInput() - 1);
    } else {
        cout << "Cart is empty!\n";
    }
}

void showApp::clearOrder() { cart.clear(); }

void showApp::exitAndSave() {
    string filename = currentUser->getName() + "_cart.txt";
    cart.saveToFile(filename, *currentUser);
}