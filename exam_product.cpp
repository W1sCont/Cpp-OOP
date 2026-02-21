#include <iostream>
#include <iomanip>
#include <string>

#include "exam_product.h"
#include "exam_order.h"

using std::cout;
using std::string;

// Product
Product::Product(string name_, double price_) : name{ name_ }, price{ price_ }, count { 1 } {}
double Product::getPrice() const { return price; }
double Product::getTotalPrice() const { return price * count; }
std::string Product::getName() const { return name; }
int Product::getCount() const { return count; }
void Product::countPP() { ++count; }
void Product::countMM() { --count; }

// Electronic
Electronic::Electronic(string name_, double price_) : Product(name_, price_) {}
void Electronic::info() const { cout << "Electronic: " << name << " | Price: " << price << " | x" << count << " | Total price: " << getTotalPrice() << endl; }

// Smartphone
Smartphone::Smartphone(string name_, double price_, int ram_) : Electronic(name_, price_), ram{ ram_ } {}
void Smartphone::info() const {
    cout << "| " << std::left << setw(10) << "Smartphone"
         << " | " << setw(20) << name
         << " | " << setw(10) << ram
         << " | " << setw(7)  << price
         << " | " << setw(5)  << count
         << " | " << setw(8)  << getTotalPrice() << " |\n";
}
string Smartphone::toFileStr() const {
    return "Electronic Smartphone: " + name + " RAM: " + std::to_string(ram) + " Price: " + std::to_string(price) + " x" + std::to_string(count);
}

// Laptop
Laptop::Laptop(string name_, double price_, string cpu_) : Electronic(name_, price_), cpu{cpu_} {}
void Laptop::info() const {
    cout << "| " << std::left << setw(10) << "Laptop"
         << " | " << setw(20) << name
         << " | " << setw(10) << cpu
         << " | " << setw(7)  << price
         << " | " << setw(5)  << count
         << " | " << setw(8)  << getTotalPrice() << " |\n";
}
string Laptop::toFileStr() const {
    return "Electronic Laptop: " + name + " CPU: " + cpu + " Price: " + std::to_string(price) + " x" + std::to_string(count);
}

// Headphones
Headphones::Headphones(string name_, double price_, bool wl_) : Electronic(name_, price_), wireless{wl_} {}
void Headphones::info() const {
    cout << "| " << std::left << setw(10) << "Headphones"
         << " | " << setw(20) << name
         << " | " << setw(10) << wireless
         << " | " << setw(7)  << price
         << " | " << setw(5)  << count
         << " | " << setw(8)  << getTotalPrice() << " |\n";
}
string Headphones::toFileStr() const {
    return "Electronic Headphones: " + name + " Wireless: " + std::to_string(wireless) + " Price: " + std::to_string(price) + " x" + std::to_string(count);
}

// SmartWatch
SmartWatch::SmartWatch(string name_, double price_, int days_) : Electronic(name_, price_), batteryLife{days_} {}
void SmartWatch::info() const {
    cout << "| " << std::left << setw(10) << "SmartWatch"
         << " | " << setw(20) << name
         << " | " << setw(10) << batteryLife
         << " | " << setw(7)  << price
         << " | " << setw(5)  << count
         << " | " << setw(8)  << getTotalPrice() << " |\n";
}
string SmartWatch::toFileStr() const {
    return "Electronic SmartWatch: " + name + " Battery life: " + std::to_string(batteryLife) + " Price: " + std::to_string(price) + " x" + std::to_string(count);
}

// Tablet
Tablet::Tablet(string name_, double price_, double size_) : Electronic(name_, price_), screenSize{size_} {}
void Tablet::info() const {
    cout << "| " << std::left << setw(10) << "Tablet"
         << " | " << setw(20) << name
         << " | " << setw(10) << screenSize
         << " | " << setw(7)  << price
         << " | " << setw(5)  << count
         << " | " << setw(8)  << getTotalPrice() << " |\n";
}
string Tablet::toFileStr() const {
    return "Electronic Tablet: " + name + " Screen size: " + std::to_string(screenSize) + " Price: " + std::to_string(price) + " x" + std::to_string(count);
}

// Food
Food::Food(string name_, double price_) : Product(name_, price_) {}
void Food::info() const {cout << "Food: " << name << " | Price: " << price << " | x" << count << " | Total price: " << getTotalPrice() << endl;
}

// Banan
Banan::Banan(string name_, double price_, string color_) : Food(name_, price_), color{color_} {}
void Banan::info() const {
    cout << "| " << std::left << setw(10) << "Banana"
         << " | " << setw(20) << name
         << " | " << setw(10) << color
         << " | " << setw(7)  << price
         << " | " << setw(5)  << count
         << " | " << setw(8)  << getTotalPrice() << " |\n";
}
string Banan::toFileStr() const {
    return "Food Banana: " + name + " Color: " + color + " Price: " + std::to_string(price) + " x" + std::to_string(count);
}

// Juice
Juice::Juice(string name_, double price_, int concentrate_) : Food(name_, price_), concentrate{concentrate_} {}
void Juice::info() const {
    cout << "| " << std::left << setw(10) << "Juice"
         << " | " << setw(20) << name
         << " | " << setw(10) << concentrate
         << " | " << setw(7)  << price
         << " | " << setw(5)  << count
         << " | " << setw(8)  << getTotalPrice() << " |\n";
}
string Juice::toFileStr() const {
    return "Food Juice: " + name + " Concentrate: " + std::to_string(concentrate) + " Price: " + std::to_string(price) + " x" + std::to_string(count);
}

// Milk
Milk::Milk(string name_, double price_, double fat_) : Food(name_, price_), fat{fat_} {}
void Milk::info() const {
    cout << "| " << std::left << setw(10) << "Milk"
         << " | " << setw(20) << name
         << " | " << setw(10) << fat
         << " | " << setw(7)  << price
         << " | " << setw(5)  << count
         << " | " << setw(8)  << getTotalPrice() << " |\n";
}
string Milk::toFileStr() const {
    return "Food Milk: " + name + " Fat: " + std::to_string(fat) + " Price: " + std::to_string(price) + " x" + std::to_string(count);
}

// Bread
Bread::Bread(string name_, double price_, string flour_) : Food(name_, price_), flourType{flour_} {}
void Bread::info() const {
    cout << "| " << std::left << setw(10) << "Bread"
         << " | " << setw(20) << name
         << " | " << setw(10) << flourType
         << " | " << setw(7)  << price
         << " | " << setw(5)  << count
         << " | " << setw(8)  << getTotalPrice() << " |\n";
}
string Bread::toFileStr() const {
    return "Food Bread: " + name + " Flour type: " + flourType + " Price: " + std::to_string(price) + " x" + std::to_string(count);
}