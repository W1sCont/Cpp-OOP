#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <iomanip>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

class Stack		// LIFO
{
private:
    enum { EMPTY = -1, FULL = 20 };		// constants
    char st[FULL + 1];
    int pt;
public:
    Stack();
    void Clear();
    bool isEmpty() const;
    bool isFull() const;
    char Push(char);
    char Pop();
    char Peek() const;	// top()
};

Stack::Stack() { pt = EMPTY; }

void Stack::Clear() { pt = EMPTY; }

bool Stack::isEmpty() const { return pt == EMPTY; }

bool Stack::isFull() const { return pt == FULL; }

char Stack::Push(char c)
{
    if (!isFull())
        st[++pt] = c;
    else
        cout << "Stack is FULL!\n";

    return c;
}

char Stack::Pop()
{
    if (!isEmpty())
        return st[pt--];
    else
        cout << "Stack is EMPTY!\n";
    return -1;
}

char Stack::Peek() const
{
    if (!isEmpty())
        return st[pt];
    else
        cout << "Stack is EMPTY!\n";
    return -1;
}



int main() {
    setlocale(LC_ALL, "");

    string str{};
    const string left{ "([{" }, right{ ")]}" };
    int n{};
    int l{}, r{};

    do {
        cout << "> ";
        getline(cin, str, ';');
        cin.ignore(100, '\n');

        n = str.length();
        if (n == 0) continue;

        Stack heap{};
        int indexError = -1;

        for (int i{ 0 }; i < n; ++i)
        {
            // ...   Push()   Pop()
            //
            l = (signed int)left.find(str[i]);
            r = (signed int)right.find(str[i]);
            if (l >= 0) {
                if (heap.isFull()) { break; }
                cout << l << "l ";
                heap.Push((char)l);
            }
            else if (r >= 0) {
                cout << r << "r ";
                if (heap.isEmpty() || heap.Pop() != r) {
                    indexError = i;
                    break;
                }
            }
            //
        }

        if (indexError == -1 && heap.isEmpty()) {
            cout << "Result is correct\n";
        } else {
            int pointerPos = (indexError != -1) ? indexError : (n - 1);
            cout << "Find error\n";
            cout << str << "\n" << std::setw(pointerPos + 1) << "^" << endl;
        }

    } while (n);

    return 0;
}