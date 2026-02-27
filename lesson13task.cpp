#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <iomanip>
#include "lesson13task.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;


// Stack
template <typename T>
class Stack : public List<T> {
public:
	Stack() : List<T>() {}
	~Stack() override = default;
	void PushHead(T n) override { List<T>::PushHead(n); }
	T PopHead() override { return List<T>::PopHead(); }
	int Size() const override { return List<T>::Size(); }
};

// Queue
template <typename T>
class Queue : public List<T> {
public:
	Queue() : List<T>() {}
	~Queue() override = default;
	void PushTail(T n) override { List<T>::PushTail(n); }
	T PopHead() override { return List<T>::PopHead(); }
	int Size() const override { return List<T>::Size(); }
};

int main()
{
	// Stack
	cout << "=== Stack Test (LIFO) ===" << endl;
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

		Stack<char> heap{};
		int indexError = -1;

		for (int i{ 0 }; i < n; ++i)
		{
			l = (signed int)left.find(str[i]);
			r = (signed int)right.find(str[i]);
			if (l >= 0) {
				cout << l << "l ";
				heap.PushHead(l);
			}
			else if (r >= 0) {
				cout << r << "r ";
				if (heap.Size() == 0 || heap.PopHead() != r) {
					indexError = i;
					break;
				}
			}
		}

		if (indexError == -1 && heap.Size() == 0) {
			cout << "Result is correct\n";
		} else {
			int pointerPos = (indexError != -1) ? indexError : (n - 1);
			cout << "Find error\n";
			cout << str << "\n" << std::setw(pointerPos + 1) << "^" << endl;
		}

	} while (n);

	// Queue
	cout << "=== Queue Test (FIFO) ===" << endl;
	Queue<int> q{};

	cout << "Adding 10, 20, 30 to Queue..." << endl;
	q.PushTail(10);
	q.PushTail(20);
	q.PushTail(30);

	cout << "Queue size: " << q.Size() << endl;

	cout << "Extracting elements: ";
	while (q.Size() > 0) {
		cout << q.PopHead() << " ";
	}
	cout << endl;

	return 0;
}