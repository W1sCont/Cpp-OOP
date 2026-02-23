#include <iostream>
#include <cstring>
#include <iomanip>

using std::cin;
using std::cout;

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
	void PushTail(char data_);
	int Size() const;
	void Clear();
	void Show() const;

	~List() { Clear(); }

	List* Clone() const {
		List* copy = new List();
		Elem* temp = Head;
		while (temp) {
			copy->PushTail(temp->Data);
			temp = temp->Next;
		}
		return copy;
	}

	Elem* operator+(const List& obj) const{
		List* result = new List(); // leaked
		Elem* temp = this->Head;
		while (temp) {
			result->PushHead(temp->Data);
			temp = temp->Next;
		}

		temp = obj.Head;
		while (temp) {
			result->PushHead(temp->Data);
			temp = temp->Next;
		}

		return result->Head;
	}

	//
	bool repeat(char val) const {
		Elem* temp = Head;
		while (temp) {
			if (temp->Data == val) return true;
			temp = temp->Next;
		}
		return false;
	}

	Elem* operator*(const List& obj) {
		List* result = new List(); // leaked
		Elem* temp = this->Head;

		while (temp) {
			if (obj.repeat(temp->Data)) {
				if (!result->repeat(temp->Data))
					result->PushHead(temp->Data);
			}
			temp = temp->Next;
		}

		return result->Head;
	}

};

void List::PushHead(char data_)
{
	// Insert(0, data_);

	Elem* temp = new Elem{};

	temp->Data = data_;
	temp->Next = Head;
	if (Head)
		Head = temp;
	else
		Head = Tail = temp;

	++Count;
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

void List::PushTail(char data_)
{
	Elem* temp = new Elem{};

	temp->Data = data_;
	temp->Next = nullptr;
	if (Head)
	{
		Elem* temp2 = Head;	//
		Elem* old = temp;

		while (temp2)
		{
			old = temp2;
			temp2 = temp2->Next;
		}

		old->Next = temp;	//
		// Tail->Next = temp;

		Tail = temp;
	}
	else
		Head = Tail = temp;

	++Count;
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
	// *
	List list1{}, list2{};

	list1.PushHead('a'); list1.PushHead('b');
	list1.PushHead('c'); list1.PushHead('d');

	list2.PushHead('c'); list2.PushHead('d');
	list2.PushHead('e'); list2.PushHead('f');

	cout << "list1: \n";
	list1.Show();
	cout << "list2: \n";
	list2.Show();

	// +
	Elem* newHead = list1 + list2;

	cout << "test +: ";
	while(newHead) {
		cout << newHead->Data << " ";
		newHead = newHead->Next;
	}
	cout << '\n';

	// *
	Elem* commonHead = list1 * list2;

	cout << "test *: ";
	while (commonHead) {
		cout << commonHead->Data << " ";
		commonHead = commonHead->Next;
	}
	cout << '\n';

	// clone
	List* list3 = list1.Clone();
	cout << "Cloned list: ";
	list3->Show();

	delete list3;
	return 0;	// FIFO   LIFO
}