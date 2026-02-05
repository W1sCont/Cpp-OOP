// #include <iostream>
// #include <cstring>
// #include <iomanip>
//
// using namespace std;
//
// enum types {Trench, Chesterfield, Duffle};
// const char* typesName[]  {"Trench", "Chesterfield", "Duffle"};
//
// class Overcoat {
// private:
//     char* name;
//     int price;
//     short type;
// public:
//     Overcoat() : name{nullptr}, price{0}, type{Trench} {
//         name = new char[20];
//         strcpy(name, "Overcoat");
//     }
//
//     Overcoat(short type_) : name{nullptr}, price{0}, type{type_} {
//         name = new char[20];
//         strcpy(name, "Overcoat");
//     }
//
//     ~Overcoat(){
//         delete[] name;
//     }
//
//     Overcoat(const Overcoat& copy_) : price{copy_.price}, type{copy_.type} {
//         if (copy_.name != nullptr) {
//             name = new char[strlen(copy_.name) + 1];
//             strcpy(name, copy_.name);
//         } else {
//             name = nullptr;
//         }
//     }
//
//     Overcoat& operator=(const Overcoat& copy_) {
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
//         type = copy_.type;
//
//         return *this;
//     }
//
//     void setData() {
//         cin >> *this;
//     }
//
//     char* getName() const { return name; }
//     int getPrice() const { return price; }
//     short getType() const { return type; }
//     const char* getTypeName() const { return typesName[type]; }
//
//     bool operator==(const Overcoat& s) const {
//         return this->type == s.type;
//     }
//
//     bool operator>(const Overcoat& s) const {
//         if (this->type != s.type) return false;
//         return this->price > s.price;
//     }
//
//     bool operator<(const Overcoat& s) const {
//         if (this->type != s.type) return false;
//         return this->price < s.price;
//     }
//
//     friend ostream& operator<<(ostream& os, const Overcoat& s);
//     friend istream& operator>>(istream& is, Overcoat& s);
//
// };
//
// ostream& operator<<(ostream& os, const Overcoat& s) {
//     os << "Name: " << s.name << ' ' << "Price: " << s.price << ' ' << "Type: " << typesName[s.type] << endl;
//     return os;
// }
//
// istream& operator>>(istream& is, Overcoat& s) {
//     char buffer[100];
//     cout << "Name > ";
//     is.ignore();
//     is.getline(buffer, 100);
//     delete[] s.name;
//     s.name = new char[strlen(buffer) + 1];
//     strcpy(s.name, buffer);
//
//     cout << "Price > ";
//     is >> s.price;
//     if (!is.good()) {
//         cout << "Invalid price. Default 100 \n";
//         s.price = 100;
//         is.clear();
//         is.ignore(100, '\n');
//     }
//
//     cout << "Type (0-Trench, 1-Chesterfield, 2-Duffle) > ";
//     is >> s.type;
//     if (!is.good() || s.type < 0 || s.type > 2) {
//         cout << "Invalid type. Default Trench \n";
//         s.type = 0;
//         is.clear();
//         is.ignore(100, '\n');
//     }
//
//
//     return is;
// }
//
//
//
// int main() {
//     setlocale(LC_ALL, "");
//
//     Overcoat o1{};
//     cout << o1;
//     cout << "Enter  o1 data" << endl;
//     o1.setData();
//
//     Overcoat o2{};
//     cout << "Enter  o2 data" << endl;
//     cin >> o2;
//     cout << o2;
//
//     Overcoat o3{Duffle};
//
//     if (o1 == o2) {
//         if (o1 > o2) {
//             cout << "First is more expensive\n";
//         } else if (o1 < o2) {
//             cout << "Second is more expensive\n";
//         } else {
//             cout << "Same price\n";
//         }
//     } else {
//         cout << "Different types - cannot compare prices\n";
//     }
//
//     if (o3 == o2) {
//         if (o2 > o3) {
//             cout << "First is more expensive\n";
//         } else if (o2 < o3) {
//             cout << "Second is more expensive\n";
//         } else {
//             cout << "Same price\n";
//         }
//     } else {
//         cout << "Different types - cannot compare prices\n";
//     }
//
//     return 0;
// }