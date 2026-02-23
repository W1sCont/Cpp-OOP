#include <iostream>
#include <iomanip>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

struct Elem
{
	char Data;
	Elem* Next;
};

class List	// singly linked list
{
	Elem* Head;
	Elem* Tail;		//
	int Count;		//
public:
	List() : Head{ nullptr }, Tail{ nullptr }, Count{ 0 } {}

	void PushHead(char);
	char PeekHead() const;
	char PopHead();
	int Size() const;
	void Clear();
	void Show() const;

	~List() { Clear(); }
};

void List::PushHead(char data_)
{
	Elem* temp = new Elem{};

	temp->Data = data_;
	temp->Next = Head;
	if (Head)
		Head = temp;
	else
		Head = Tail = temp;

	++Count;
}

char List::PopHead()
{
	if (Head)
	{
		char ret{};
		Elem* temp{ Head };
		ret = temp->Data;
		Head = temp->Next;

		delete temp;
		--Count;
		return ret;
	}
	else
		return -1;
}

char List::PeekHead() const
{
	if (Head)
	{
		return Head->Data;
	}
	else
		return -1;
}

int List::Size() const { return Count; }

void List::Clear()
{
	while (Head)
		PopHead();
}

void List::Show() const
{
	Elem* temp{ Head };

	while (temp)
	{
		cout << temp->Data << " ";
		temp = temp->Next;
	}
	cout << "\n";
}


int main()
{
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

		List heap{};
		int indexError = -1;

		for (int i{ 0 }; i < n; ++i)
		{
			l = (signed int)left.find(str[i]);
			r = (signed int)right.find(str[i]);
			if (l >= 0) {
				cout << l << "l ";
				heap.PushHead((char)l);
			}
			else if (r >= 0) {
				cout << r << "r ";
				if (heap.PeekHead() == -1 || heap.PopHead() != r) {
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

	return 0;	// FIFO   LIFO
}