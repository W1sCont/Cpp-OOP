#pragma once

#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::string;

template <typename T>
struct Elem
{
	T data;
	Elem* next;
	Elem* prev;
};

template <typename T>
class List		// doubly linked list
{
protected:
	Elem<T>* Head;
	Elem<T>* Tail;
	int Count;
public:
	List() : Head{ nullptr }, Tail{ nullptr }, Count{ 0 } {}

	List(const T&);

	virtual ~List() { DelAll(); }

	virtual int Size() const { return Count; }

	Elem<T>* GetElem(int n) const;
	void DelAll();
	void Del(int pos = 0);
	void Insert(int pos = 0);
	virtual void PushTail(T n);
	virtual void PushHead(T n);
	T PopTail();
	virtual T PopHead();
	void Show() const ;
	void Show(int pos) const;

	List<T>& operator = (const List<T>&);
	List<T> operator + (const List<T>&);

	bool operator == (const T&);
	bool operator != (const T&);
	bool operator <= (const T&);
	bool operator >= (const T&);
	bool operator < (const T&);
	bool operator > (const T&);

	List<T> operator-();		// revers
};

template <typename T>
List<T>::List(const T& L)
{
	Head = Tail = nullptr;
	Count = 0;
	Elem<T>* temp = L.Head;

	while (temp)
	{
		AddTail(temp->data);
		temp = temp->next;
	}
}

template <typename T>
void List<T>::PushHead(T n)
{
	Elem<T>* temp = new Elem<T>;
	temp->prev = 0;
	temp->data = n;
	temp->next = Head;
	if (Head != 0)
		Head->prev = temp;
	if (Count == 0)
		Head = Tail = temp;
	else
		Head = temp;
	Count++;
}

template <typename T>
void List<T>::PushTail(T n)
{
	Elem<T>* temp = new Elem<T>;
	temp->next = 0;
	temp->data = n;
	temp->prev = Tail;
	if (Tail != 0)
		Tail->next = temp;
	if (Count == 0)
		Head = Tail = temp;
	else
		Tail = temp;
	Count++;
}

template <typename T>
T List<T>::PopTail() {
	if (Count == 0) return T{};

	Elem<T>* temp = Tail;
	T val = temp->data;

	Tail = Tail->prev;

	if (Tail != nullptr)
		Tail->next = nullptr;
	else
		Head = nullptr;

	delete temp;
	Count--;
	return val;
}

template <typename T>
T List<T>::PopHead() {
	if (Count == 0) return T{};

	Elem<T>* temp = Head;
	T val = temp->data;

	Head = Head->next;

	if (Head != nullptr)
		Head->prev = nullptr;
	else
		Tail = nullptr;

	delete temp;
	Count--;
	return val;
}

template <typename T>
void List<T>::Insert(int pos)
{
	if (pos == 0)
	{
		cout << "Input position: ";
		cin >> pos;
	}
	if (pos < 1 || pos > Count + 1)
	{
		cout << "Incorrect position!\n";
		return;
	}
	if (pos == Count + 1)
	{
		int data;
		cout << "Input new number: ";
		cin >> data;
		PushTail(data);
		return;
	}
	else if (pos == 1)
	{
		int data;
		cout << "Input new number: ";
		cin >> data;
		PushHead(data);
		return;
	}
	int i = 1;

	Elem<T>* Ins = Head;
	while (i < pos)
	{
		Ins = Ins->next;
		i++;
	}

	Elem<T>* PrevIns = Ins->prev;
	Elem<T>* temp = new Elem<T>;
	cout << "Input new number: ";
	cin >> temp->data;
	if (PrevIns != 0 && Count != 1)
		PrevIns->next = temp;
	temp->next = Ins;
	temp->prev = PrevIns;
	Ins->prev = temp;
	Count++;
}

template <typename T>
void List<T>::Del(int pos)
{
	if (pos == 0)
	{
		cout << "Input position: ";
		cin >> pos;
	}
	if (pos < 1 || pos > Count)
	{
		cout << "Incorrect position!\n";
		return;
	}
	int i = 1;
	Elem<T>* Del = Head;
	while (i < pos)
	{
		Del = Del->next;
		i++;
	}
	Elem<T>* PrevDel = Del->prev;
	Elem<T>* AfterDel = Del->next;
	if (PrevDel != 0 && Count != 1)
		PrevDel->next = AfterDel;
	if (AfterDel != 0 && Count != 1)
		AfterDel->prev = PrevDel;
	if (pos == 1)
		Head = AfterDel;
	if (pos == Count)
		Tail = PrevDel;
	delete Del;
	Count--;
}

template <typename T>
void List<T>::Show(int pos) const
{
	if (pos < 1 || pos > Count)
	{
		cout << "Incorrect position!\n";
		return;
	}
	Elem<T>* temp;
	if (pos <= Count / 2)
	{
		temp = Head;
		int i = 1;
		while (i < pos)
		{
			temp = temp->next;
			i++;
		}
	}
	else
	{
		temp = Tail;
		int i = 1;
		while (i <= Count - pos)
		{
			temp = temp->prev;
			i++;
		}
	}
	cout << pos << " element: ";
	cout << temp->data << "\n";
}

template <typename T>
void List<T>::Show() const
{
	if (Count != 0)
	{
		Elem<T>* temp = Head;
		cout << "( ";
		while (temp->next != 0)
		{
			cout << temp->data << ", ";
			temp = temp->next;
		}
		cout << temp->data << " )\n";
	}
}

template <typename T>
void List<T>::DelAll()
{
	while (Count != 0)
		Del(1);
}

template <typename T>
Elem<T>* List<T>::GetElem(int pos) const
{
	Elem<T>* temp = Head;
	if (pos < 1 || pos > Count)
	{
		cout << "Incorrect position!\n";
		return 0;
	}
	int i = 1;
	while (i < pos && temp)
	{
		temp = temp->next;
		i++;
	}
	if (temp == 0)
		return 0;
	else
		return temp;
}

template <typename T>
List<T>& List<T>::operator = (const List<T>& L)
{
	if (this == &L)
		return *this;
	this->~List(); // DelAll();
	Elem<T>* temp = L.Head;
	while (temp)
	{
		AddTail(temp->data);
		temp = temp->next;
	}
	return *this;
}

template <typename T>
List<T> List<T>::operator+(const List<T>& L)
{
	List<T> Result(*this);
	Elem<T>* temp = L.Head;
	while (temp)
	{
		Result.PushTail(temp->data);
		temp = temp->next;
	}

	return Result;
}

template <typename T>
bool List<T>::operator == (const T& L)
{
	if (Count != L.Count)
		return false;
	Elem<T>* t1, *t2;
	t1 = Head;
	t2 = L.Head;
	while (t1 != 0)
	{
		if (t1->data != t2->data)
			return false;
		t1 = t1->next;
		t2 = t2->next;
	}
	return true;
}

template <typename T>
bool List<T>::operator!=(const T& L) { return !(*this == L); }

template <typename T>
bool List<T>::operator>=(const T& L)
{
	if (Count > L.Count)
		return true;
	if (*this == L)
		return true;
	return false;
}

template <typename T>
bool List<T>::operator <= (const T& L)
{
	if (Count < L.Count)
		return true;
	if (*this == L)
		return true;
	return false;
}

template <typename T>
bool List<T>::operator > (const T& L)
{
	if (Count > L.Count)
		return true;
	return false;
}

template <typename T>
bool List<T>::operator < (const T& L)
{
	if (Count < L.Count)
		return true;
	return false;
}

template <typename T>
List<T> List<T>::operator-()
{
	List<T> Result;
	Elem<T>* temp = Head;
	while (temp)
	{
		Result.PushHead(temp->data);
		temp = temp->next;
	}
	return Result;
}