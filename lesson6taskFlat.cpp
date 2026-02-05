// #include <iostream>
// #include <cstring>
// #include <iomanip>
//
// using namespace std;
//
//
// class Flat {
// private:
//     char* name;
//     int price;
//     double area;
//
// public:
//     Flat() : name{nullptr}, price{0}, area(0.0) {
//         name = new char[20];
//         strcpy(name, "Flat 1");
//     }
//
//     Flat(double area_) : name{nullptr}, price{0}, area(area_) {
//         name = new char[20];
//         strcpy(name, "Flat 1");
//     }
//
//     ~Flat(){
//         delete[] name;
//     }
//
//     Flat(const Flat& copy_) : price{copy_.price}, area{copy_.area} {
//         if (copy_.name != nullptr) {
//             name = new char[strlen(copy_.name) + 1];
//             strcpy(name, copy_.name);
//         } else {
//             name = nullptr;
//         }
//     }
//
//     Flat& operator=(const Flat& copy_) {
//         if (this == &copy_) return *this;
//
//         delete[] name;
//
//         if (copy_.name != nullptr) {
//             name = new char[strlen(copy_.name) + 1];
//             strcpy(name, copy_.name);
//         } else {
//             name = nullptr;
//         }
//
//         price = copy_.price;
//         area = copy_.area;
//
//         return *this;
//     }
//
//     void setData() {
//         char buffer[100];
//         cout << "Enter flat name: ";
//         // cin.ignore();
//         cin.getline(buffer, 100);
//
//         delete[] name;
//         name = new char[strlen(buffer) + 1];
//         strcpy(name, buffer);
//
//         cout << "Enter price: ";
//         cin >> price;
//         if (!cin.good()) {
//             cout << "Invalid price. Default 1000 \n";
//             price = 1000;
//             cin.clear();
//             cin.ignore(100, '\n');
//         }
//
//         cout << "Enter area: ";
//         cin >> this->area;
//         if (!cin.good()) {
//             cout << "Invalid area. Default 30 \n";
//             area = 30;
//             cin.clear();
//             cin.ignore(100, '\n');
//         }
//     }
//
//     void print() const {
//         cout << "Flat name: " << name << " || " << "Price: " << price << " || " << "Area: " << area << endl;
//     }
//
//     const char* getName() const { return name; }
//     int getPrice() const { return price; }
//     double getArea() const { return area; }
//
//     bool operator==(const Flat& s) const {
//         return this->area == s.area;
//     }
//
//     bool operator>(const Flat& s) const {
//         return this->price > s.price;
//     }
//
//     bool operator<(const Flat& s) const {
//         return this->price < s.price;
//     }
// };
//
// int main() {
//     setlocale(LC_ALL, "");
//
//     Flat f1{};
//     f1.print();
//     f1.setData();
//
//     Flat f2{34.5};
//     f2.print();
//
//     if (f1 > f2) {
//         cout << f1.getName() << " is more expensive than " << f2.getName() << endl;
//     } else if (f1 < f2) {
//         cout << f2.getName() << " is more expensive than " << f1.getName() << endl;
//     } else {
//         cout << "Same price" << f1.getPrice() << "\n";
//     }
//
//     return 0;
// }