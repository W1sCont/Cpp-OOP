#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <iomanip>
#include <stack>
#include <string>
#include <fstream>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::stack;

int main() {
    setlocale(LC_ALL, "");

    const char left{ '<' }, right{ '>' }, closing { '/'};

    std::ifstream file("validator.txt");
    if (!file.is_open()) cout << "Open error\n";

    stack<string> heap{};
    char ch{};
    string log{};
    bool idxError = false;

    while (file.get(ch)) {
        string tag{};
        log += ch;
        if (ch == left) {
            while (file.get(ch)) {
                log += ch;
                if (ch == right) { break;}
                tag += ch;
                if (tag.find(' ') != string::npos) {
                    idxError = true;
                    break;
                }
            }
            if (idxError) break;
        }

        if (tag[0] == closing) {
            if (heap.empty()) {
                idxError = true;
                break;
            }
            if (heap.top() == tag.substr(1)) {
                heap.pop();
                continue;
            }
            else {
                idxError = true;
                break;
            }
        }
        if (!tag.empty()) heap.push(tag);
    }

    if (idxError || !heap.empty()) {
        cout << log << " <-Error\n";
    }
    else {
        cout << log << "\n all valid \n";
    }

    return 0;
}