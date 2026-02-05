// #define _CRT_SECURE_NO_WARNINGS
//
// #include <iostream>
// #include <iomanip>
// #include <cstring>
//
// using std::cin;
// using std::cout;
// using std::endl;
//
// template <typename T>
// void Resize(T*& arr, int& Size, int newSize) {
// 	if (newSize == Size) return;
//
// 	int tempSize = Size > newSize ? newSize : Size;
//
// 	T* tempArr = new T[tempSize];
// 	for (int i = 0; i < tempSize; ++i) {
// 		tempArr[i] = arr[i];
// 	}
//
// 	delete[] arr;
// 	arr = tempArr;
// 	Size = tempSize;
// }
//
// char* set() {
// 	char buffer[100];
// 	cout << "> ";
// 	cin.ignore();
// 	cin.getline(buffer, 100);
//
// 	if (!cin.good()) {
// 		cin.clear();
// 		cin.ignore(100, '\n');
// 	}
//
// 	char* result = new char[strlen(buffer) + 1];
// 	strcpy(result, buffer);
//
// 	return result;
// }
//
// template<typename T>
// T set() {
// 	T value{};
// 	cout << "> ";
// 	cin >> value;
// 	if (!cin.good()) {
// 		cout << "invalid type default ";
// 		cin.clear();
// 		cin.ignore(100, '\n');
// 	}
// 	return value;
// }
//
//
// int main() {
// 	setlocale(LC_ALL, "");
// 	srand(time(nullptr));
//
// 	cout << "Enter int ";
// 	int valueInt = set<int>();
// 	cout << valueInt << endl;
//
// 	cout << "Enter float ";
// 	float valueFloat = set<float>();
// 	cout << valueFloat << endl;
//
// 	cout << "Enter string ";
// 	char* valueString = set();
// 	cout << valueString << endl;
//
// 	delete[] valueString;
//
// 	int Size{5}, newSize{3};
// 	int* numb = new int[Size];
// 	for (int i{0}; i < Size; ++i) {
// 		numb[i] = rand() % 5;
// 		cout << numb[i] << ' ';
// 	}
// 	cout << endl;
//
// 	Resize(numb, Size, newSize);
// 	for (int i{0}; i < newSize; ++i) {
// 		cout << numb[i] << ' ';
// 	}
// 	cout << endl;
//
//
// 	delete[] numb;
// 	return 0;
// }