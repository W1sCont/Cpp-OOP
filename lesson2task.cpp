// #define _CRT_SECURE_NO_WARNINGS
// #include <iostream>
// #include <iomanip>
// #include <cctype>
// #include <cstring>
// #include <locale> //
// // #include <windows.h> // +-
// // #include <string> // --- !
//
// using namespace std;
//
// const int DefLeng{ 80 };
//
// class String {
// private:
//     char* str;
//     int size;
//     static int count;
// public:
//     String() : size{ DefLeng },str{ new char[DefLeng + 1] {0} } {count++;}
//
//     String(int size_p) // :
//     {
//         str = new char[size_p + 1] { 0 };
//         size = size_p;
//         count++;
//     }
//
//     String(const char* str_p) {
//         if (str_p == nullptr) {
//             size = 0;
//             str = new char[1];
//             str[0] = '\0';
//         } else {
//             size = strlen(str_p);
//             str = new char[size + 1];
//             strcpy(str, str_p);
//         }
//         count++;
//     }
//
//     String(const String& s) {
//         size = s.size;
//         str = new char[size + 1];
//         strcpy(str, s.str);
//         count++;
//     }
//
//     void setStr(const char* str_p);
//     void input();
//     void print();
//     char* getStr() {return str;}
//     int len() {return size;}
//
//     static int getCount() { return count; }
//
//     ~String() {
//         delete[] str;
//         count--;
//     }
// };
//
// int String::count = 0;
//
// void String::setStr(const char* str_p) {
//     delete[] str;
//     int len = 0;
//     while (str_p[len] != '\0') {
//         len++;
//     }
//
//     str = new char[len + 1];
//     size = len;
//
//     for(int i = 0; i < size; i++) {
//         str[i] = str_p[i];
//     }
//     str[size] = '\0';
// }
//
// void String::print() {
//     // int len = 0;
//     // while (str[len] != '\0'){
//     //     std::cout << str[len];
//     //     len++;
//     // }
//     // std::cout << std::endl;
//
//     if (getStr() != nullptr) {
//         std::cout << getStr();
//     }
//     std::cout << std::endl;
// }
//
// void String::input() {
//     int temp_size = 1000;
//     char* temp_arr = new char[temp_size];
//     cout << '>';
//     cin.getline(temp_arr, temp_size);
//
//     int new_len = strlen(temp_arr);
//
//     delete[] str;
//
//     size = new_len;
//     str = new char[size + 1];
//     strcpy(str, temp_arr);
//
//     delete[] temp_arr;
// }
//
// // ...
//
// int main()
// {
//     setlocale(LC_ALL, "");
//     //
//     // SetConsoleCP(1251);
//     // SetConsoleOutputCP(1251);
//     // system("chcp 1251 >nul"); //
//
//     String str1{};
//     cout << str1.len() << endl;
//
//     String str2{ 20 };
//     cout << str2.len() << endl;
//
//     String str3{"Hello"};
//     cout << str3.len() << endl;
//     cout << str3.getStr() << endl;
//
//     str3.setStr("Hello, world!");
//     cout << str3.len() << endl;
//     str3.print();
//     std::cout << "=======" << std::endl;
//     str3.input();
//     str3.print();
//     cout << str3.len() << endl;
//     // ...
//     // str1.input();
//     // cout << str1.len() << endl;
//     // str1.print();
//     // cout << "obj count: " << String::getCount() << endl;
//
//     return 0;
// }