#include <iostream>
#include <string>
#include <ctime>

#define SIZE_BUFF 80

using std::cin;
using std::cout;
using std::endl;
using std::string;

const string USERS[] = {"PM", "UI/UX", "QA", "FrontDev", "BackDev", "DevOps"};
const int USERS_COUNT = 6;
const int USER_PRIORITY[] = {5, 4, 3, 2, 1, 1};

struct Request {
	int userID;
	int userPri;
	string printTime;
};


class QueuePri		// FIFO
{
private:
	Request* arr;
	int capacity;	// max size
	int size;
public:
	QueuePri(int n) : capacity{ n }, size{ 0 }, arr{ new Request[n] {} } {}
	QueuePri() : QueuePri(20) {}
	QueuePri(const QueuePri&) = delete;
	QueuePri& operator=(const QueuePri&) = delete;

	void Clear() { size = 0; }
	bool isEmpty() const { return size == 0; }
	bool isFull() const { return size == capacity; }
	int Size() const { return size; }
	int Front() const;
	int Back() const;
	bool Push(int, int, string);
	Request Pop();
	bool Show() const;

	~QueuePri() { delete[] arr; }

};


int QueuePri::Front() const { return isEmpty() ? -1 : arr[size - 1].userID; }

int QueuePri::Back() const { return isEmpty() ? -1 : arr[0].userID; }

bool QueuePri::Push(int data, int prior, string str)
{
	int idx{ size };	//

	if (!isFull())
	{
		for (idx = 0; idx < size; ++idx)
			if (arr[idx].userPri < prior)
				break;

		for (int i{ size - 1 }; i >= idx; --i)
		{ arr[i + 1] = arr[i]; }

		arr[idx] = { data, prior, str };
		++size;
		return true;
	}
	else
		return false;
}

Request QueuePri::Pop()
{
	int idx{ 0 };

	if (!isEmpty())
	{
		Request temp = arr[idx];		// [0]
		for (int i{ idx }; i < size - 1; ++i) { arr[i] = arr[i + 1]; }
		--size;				//
		return temp;
	}
	else
		return {-1, -1, ""};
}

bool QueuePri::Show() const
{
	if (!isEmpty())
	{
		for (int i{ 0 }; i < size; ++i)
			cout << USERS[arr[i].userID] << " Prt: " << arr[i].userPri << " Time: " << arr[i].printTime << '\n';
		cout << '\n';
		return true;
	}
	else {
		cout << "Empty" << endl;
		return false;
	}
}

void mySleep(double delay) {
	time_t start{ 0 }, end{ 0 };
	double d{ 0.0 };
	start = time(nullptr);
	while (true) {
		end = time(nullptr);
		d = difftime(end, start);
		if (d >= delay) break;
	}
}

char* currentDateTime(char* buffer, time_t t) {
	// time_t t = time(nullptr);
	tm* now = localtime(&t);
	strftime(buffer, SIZE_BUFF, "%F %X", now);
	return buffer;
}

class PrintQueue {
private:
	Request* printQueue;
	int capacity;
	int size;
public:
	// PrintQueue() : size{0}, capacity{0} { userIdx = new int[size]; priority = new int[size]; requestTime = new string[size]; }
	PrintQueue() = delete;
	explicit PrintQueue(int n) : capacity{ n }, size{ 0 }, printQueue{ new Request[n] {} } {}
	~PrintQueue() { delete[] printQueue; }
	PrintQueue(const PrintQueue&) = delete;
	PrintQueue& operator=(const PrintQueue&) = delete;

	bool isEmpty() const { return size == 0; }
	bool isFull() const { return size == capacity; }

	bool Push(int data, int prior, string str)
	{
		int idx{ size };	//

		if (!isFull())
		{
			printQueue[idx] = { data, prior, str };
			++size;
			return true;
		}
		else
			return false;
	}

	Request Pop()
	{
		int idx{ 0 };

		if (!isEmpty())
		{
			Request temp = printQueue[idx];		// [0]
			for (int i{ idx }; i < size - 1; ++i) { printQueue[i] = printQueue[i + 1]; }
			--size;				//
			return temp;
		}
		else
			return {-1, -1, ""};
	}

	void Show() const {
		cout << "Printer: \n";
		for (int i{ 0 }; i < size; ++i)
			cout << USERS[printQueue[i].userID] << " Prt: " << printQueue[i].userPri << " Time: " << printQueue[i].printTime << '\n';
		cout << '\n';
	}
};



int main()
{
	setlocale(LC_ALL, "");
	// system("chcp 1251 >nul");	// +-

	const int Test = 5;

	int data{}, pri{};
	QueuePri Q(Test);
	PrintQueue P{Test};

	srand((int)time(nullptr));

	cout << Q.Size() << "\n";

	char buffer[SIZE_BUFF]{};
	string st{};

	double d{};
	int count{Test};

	while (true)
	{
		d = (rand() % 30 + 10) / 10.0;	// 1.0 ... 3.0
		// Sleep(d * 1000.0);
		mySleep(d);
		st = currentDateTime(buffer, time(nullptr));
		cout << "Delay " << d << " Current Time and Date: " << st << ' ';

		data = rand() % USERS_COUNT;
		pri = USER_PRIORITY[data];
		cout << data << "/" << pri << '\n';
		if (!Q.Push(data, pri, st))
			cout << "Error!\n";

		--count;
		if (count == 0) { break; }
	}

	cout << "\n" << Q.Size() << "\n";
	Q.Show();

	cout << Q.Front() << "\n";
	cout << Q.Back() << "\n";



	for (int i{ 0 }; i < 3; ++i)
	{
		Request temp = Q.Pop();
		P.Push(temp.userID, temp.userPri,temp.printTime);
	}
	cout << "3xPop()\n";
	Q.Show();
	P.Show();

	for (int i{ 0 }; i < 3; ++i)
	{
		Request temp = Q.Pop();
		P.Push(temp.userID, temp.userPri,temp.printTime);
	}
	cout << "3xPop()\n";
	Q.Show();
	P.Show();




	return 0;
}