#pragma once

using std::cin;
using std::cout;
using std::endl;
using std::string;

#include <string>
#include <iostream>

class Product {
protected:
    string name;
    double price;
    int count;
public:
    Product() = delete;
    Product(string name_, double price_);
    virtual ~Product() = default;
    virtual void info() const = 0;
    virtual double getPrice() const;
    virtual double getTotalPrice() const;
    virtual string getName() const;
    virtual string toFileStr() const = 0;
    int getCount() const;
    void countPP();
    void countMM();
};

class Food : public Product {
public:
    Food(string name_, double price_);
    virtual void info() const;
    virtual string toFileStr() const override = 0;
};

class Banan : public Food {
protected:
    string color;
public:
    Banan(string name_, double price_, string color_);
    void info() const override;
    virtual string toFileStr() const override;
};

class Juice : public Food {
protected:
    int concentrate;
public:
    Juice(string name_, double price_, int concentrate_);
    void info() const override;
    virtual string toFileStr() const override;
};

class Milk : public Food {
    double fat;
public:
    Milk(string name_, double price_, double fat_);
    void info() const override;
    string toFileStr() const override;
};

class Bread : public Food {
    string flourType;
public:
    Bread(string name_, double price_, string flour_);
    void info() const override;
    string toFileStr() const override;
};

class Electronic : public Product {
public:
    Electronic(string name_, double price_);
    virtual void info() const;
    virtual string toFileStr() const override = 0;
};

class Smartphone : public Electronic {
protected:
    int ram;
public:
    Smartphone() = delete;
    Smartphone(string name_, double price_, int ram_);
    virtual void info() const override;
    virtual string toFileStr() const override;
};

class Laptop : public Electronic {
    string cpu;
public:
    Laptop(string name_, double price_, string cpu_);
    void info() const override;
    string toFileStr() const override;
};

class Headphones : public Electronic {
    bool wireless;
public:
    Headphones(string name_, double price_, bool wl_);
    void info() const override;
    string toFileStr() const override;
};

class SmartWatch : public Electronic {
    int batteryLife;
public:
    SmartWatch(string name_, double price_, int days_);
    void info() const override;
    string toFileStr() const override;
};

class Tablet : public Electronic {
    double screenSize;
public:
    Tablet(string name_, double price_, double size_);
    void info() const override;
    string toFileStr() const override;
};

class productFactory {
public:
    static Product* createFactory(int type) {
        switch(type) {
            case 1: return new Banan("Cavendish", 3, "yellow");
            case 2: return new Banan("Blue Java", 3, "blue");
            case 3:  return new Milk("Galychyna", 1.5, 2.5);
            case 4:  return new Bread("Baguette", 1.0, "Wheat");
            case 5: return new Juice("Apple", 2, 80);
            case 6:  return new Laptop("MacBook M3", 2500, "M3 Pro");
            case 7: return new Headphones("Sony XM5", 350, true);
            case 8: return new SmartWatch("Apple Watch 9", 450, 2);
            case 9: return new Tablet("iPad Air", 700, 10.9);
            case 10: return new Smartphone("Iphone 15 RAM 8", 1500, 8);
            case 11: return new Smartphone("Iphone 15 RAM 16", 1700, 16);
            default: return nullptr;
        }
    }
};

class Customers {
protected:
    string name;
    bool isVIP;
public:
    Customers() = delete;
    Customers(string name_, bool vip) : name{ name_ }, isVIP{ vip } {}
    string getName() const { return name; }
    bool getVIP() const { return isVIP; }
    string toFileStr() const { return "CUSTOMER " + name + ' ' + (isVIP ? "1" : "0"); }
};

inline int choiceInput() {
    int choice{};
    while (true) {
        if (cin >> choice) {
            cin.ignore(1000, '\n');
            return choice;
        }
        else {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid choice! Please enter a number > ";
        }
    }
}