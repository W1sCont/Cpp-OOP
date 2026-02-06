#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <cctype>
#include <cstring>
#include <locale> //
#include <initializer_list>
// #include <windows.h> // +-
// #include <string> // --- !

using namespace std;

const int DefLeng{ 80 };

class String {
private:
    char* str = nullptr;
    int size = 0;
    static int count;
public:
    // String() : size{ DefLeng },str{ new char[DefLeng + 1] {0} } {count++; cout << "Constructor called \n";}
    String() = default; // init private value for task)

    String(int size_p) // :
    {
        str = new char[size_p + 1] { 0 };
        size = size_p;
        count++;
        cout << "Constructor called \n";
    }

    String(const char* str_p) {
        if (str_p == nullptr) {
            size = 0;
            str = new char[1];
            str[0] = '\0';
        } else {
            size = strlen(str_p);
            str = new char[size + 1];
            strcpy(str, str_p);
        }
        count++;
        cout << "Constructor called \n";
    }

    // String(const String& s) {
    //     size = s.size;
    //     str = new char[size + 1];
    //     strcpy(str, s.str);
    //     count++;
    // }

    String(const String& s) = delete; // for task

    String& operator=(const String& s) {
        if (this == &s) return *this;

        delete[] str;

        size = s.size;
        str = new char[size + 1];
        strcpy(str, s.str);

        return *this;
    }

    explicit String(String&& s) noexcept {
        str = s.str;
        size = s.size;

        s.str = nullptr;
        s.size = 0;

        count++;
        cout << "Move constructor called \n";
    }

    char operator[](int index) const {
        if (str == nullptr || index >= size || index < 0) {
            cout << "Invalid index." << endl;
            return '-';
        }
        return str[index];
    }

    int operator()(const char ch) const {
       for (int i{0}; i < size; ++i) {
           if (str[i] == ch) { return i; }
       }
       return -1;
    }

    operator int() const {
        return size;
    }

    operator const char*() const {
        return (str != nullptr) ? str : "char";
    }

    void setStr(const char* str_p);
    void input();
    void print();
    char* getStr() const {return str;}
    int len() const {return size;}

    static int getCount() { return count; }

    ~String() {
        delete[] str;
        count--;
    }
};

int String::count = 0;

void String::setStr(const char* str_) {
    if (str_ == nullptr) return;

    delete[] str;

    size = strlen(str_);
    str = new char[size + 1];
    strcpy(str, str_);
}

void String::print() {
    if (getStr() != nullptr) {
        std::cout << getStr();
    }
    std::cout << std::endl;
}

void String::input() {
    int temp_size = 1000;
    char* temp_arr = new char[temp_size];
    cout << '>';
    cin.getline(temp_arr, temp_size);

    int new_len = strlen(temp_arr);

    delete[] str;

    size = new_len;
    str = new char[size + 1];
    strcpy(str, temp_arr);

    delete[] temp_arr;
}

// ...

int main()
{
    setlocale(LC_ALL, "");
    //

    String s1("Hello");
    String s2("World");
    String s3;
    s3 = s2;
    s3.print();
    // String s5 = move(s1); // delete
    // s5.print();

    char i2 = s2[2];
    char i23 = s2[23];
    int g = s2('g');
    int l = s2('l');

    cout << "s2[2] > " << i2 << endl;
    cout << "s2[23] > " << i23 << endl;
    cout << "s2('g') > " << g << endl;
    cout << "s2('l') > " << l << endl;

    int length = s2;
    cout << "Length s2: " << length << endl;

    if (s2 > 3) {
        cout << "s2 > 3" << endl;
    }
    const char* raw = s1;
    cout << "String s1: " << raw << endl;

    // SetConsoleCP(1251);
    // SetConsoleOutputCP(1251);
    // system("chcp 1251 >nul"); //

    // String str1{};
    // cout << str1.len() << endl;
    //
    // String str2{ 20 };
    // cout << str2.len() << endl;
    //
    // String str3{"Hello"};
    // cout << str3.len() << endl;
    // cout << str3.getStr() << endl;
    //
    // str3.setStr("Hello, world!");
    // cout << str3.len() << endl;
    // str3.print();
    // std::cout << "=======" << std::endl;
    // str3.input();
    // str3.print();
    // cout << str3.len() << endl;
    // ...
    // str1.input();
    // cout << str1.len() << endl;
    // str1.print();
    // cout << "obj count: " << String::getCount() << endl;

    return 0;
}