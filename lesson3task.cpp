// #define _CRT_SECURE_NO_WARNINGS
//
// #include <iostream>
// #include <iomanip>
// #include <fstream>
// #include <cctype>
// #include <cstring>
//
// using std::cin;
// using std::cout;
// using std::endl;
//
//
// char* setText(char* &field, const char* prompt, char* text){
// 	int maxSize{100};
//
// 	if (strlen(prompt) > 0) {
// 		cout << prompt;
// 		cin.getline(text, maxSize);
// 	}
// 	//if (field != nullptr && strlen(field) > 0)
// 		delete[] field;
// 	field = new char[strlen(text) + 1]{ 0 };
// 	strcpy(field, text);
// 	return text;
// }
//
//
// class Flat;
//
//
// class Human{
// private:
// 	char* name;
// 	char* surname;
// 	char* phone;
// 	int age;
//
// public:
// 	Human(const char* name_, const char* surname_, const char* phone_, int age_) {
// 		name = surname = phone = nullptr;
// 		setText(name, "", (char*)name_);
// 		setText(surname, "", (char*)surname_);
// 		setText(phone, "", (char*)phone_);
// 		age = age_;
// 	}
//
// 	Human() : Human("", "", "", 0) {};
//
// 	// copy constructor +++
// 	Human(const Human& copy_) {
// 		name = surname = phone = nullptr;
// 		setText(name, "", copy_.name);
// 		setText(surname, "", copy_.surname);
// 		setText(phone, "", copy_.phone);
// 		age = copy_.age;
// 	}
//
// 	Human& operator=(const Human& obj) {
// 		if (&obj == this){ return *this; }
//
// 		setText(name, "", obj.name);
// 		setText(surname, "", obj.surname);
// 		setText(phone, "", obj.phone);
// 		age = obj.age;
//
// 		return *this;
// 	}
//
// 	Human& input();
//
// 	void setAge(const int age_) { age = age_; }
//
// 	void  print() const { cout << "Name: " << name << ", " << "Surname: " << surname << ", " << "Phone: " << phone << ", " << "Age: " << age << endl; }
//
// 	~Human() {
// 		delete[] name;
// 		delete[] surname;
// 		delete[] phone;
// 	}
//
// 	friend Flat;		// !
// };
//
//
// Human& Human::input() {
// 	char text[100]{ 0 };
// 	setText(name, "Name > ", text);
// 	setText(surname, "Surname > ", text);
// 	setText(phone, "Phone > ", text);
//
// 	cout << "Age > ";
// 	cin >> age;
// 	// check ...
// 	if (!cin.good() || age < 0 || age > 120) {
// 		cin.clear();
// 		cin.ignore(100, '\n');
// 		cout << "It's not age, I think you are 23 y.o." << endl;
// 		age = 23;
// 	}
// 	else {
// 		cin.ignore(100, '\n');
// 	}
// 	return *this;
// }
//
//
// class Flat {
// private:
// 	Human* humans;
// 	int count;		// count of humans
// 	int number;		// number of flat
//
// 	void resize(int newCount);	// + add
//
//
// public:
// 	Flat(int num) : humans{ nullptr }, count{ 0 }, number{ num } {}	// +++
//
// 	Flat() : humans{ nullptr }, count{ 0 }, number{ 0 } {}
//
// 	// copy constructor +++
// 	Flat(const Flat& s) {
// 		count = s.count;
// 		number = s.number;
// 		if (s.humans != nullptr) {
// 			humans = new Human[count];
// 			for (int i = 0; i < count; ++i) {
// 				humans[i] = s.humans[i];
// 			}
// 		} else {
// 			humans = nullptr;
// 		}
// 	}
//
// 	Flat& operator=(const Flat& obj) {
// 		if (&obj == this){ return *this; }
//
// 		delete[] humans;
//
// 		count = obj.count;
// 		number = obj.number;
// 		humans = new Human[count];
// 		for (int i = 0; i < count; ++i) {
// 			humans[i] = obj.humans[i];
// 		}
//
// 		return *this;
// 	}
//
// 	Flat& add(const Human& obj) {
// 		resize(count + 1);
// 		humans[count - 1] = obj;
//
// 		return *this;
// 	}
//
// 	Flat& add() {
// 		resize(count + 1);
// 		number += 1;					//
// 		humans[count - 1].input();		//
//
// 		return *this;
// 	}
//
// 	Flat& deliteIndex(int num) {
// 		if (num < 0 || num >= count) {
// 			cout << "Error: Invalid index!" << endl;
// 			return *this;
// 		}
//
// 		Human* humansNew = new Human[count - 1];
//
// 		for (int i = 0, j = 0; i < count; i++) {
// 			if (i == num) continue;
//
// 			humansNew[j] = humans[i];
// 			j++;
// 		}
//
// 		delete[] humans;
// 		humans = humansNew;
// 		count--;
//
// 		return *this;
// 	}
//
// 	void setNumber(int num) { number = num; }
//
// 	int getCount() { return count; }
//
// 	void  print() const { // +++
// 		for (int i{}; i < count; ++i) {
// 			humans[i].print();
// 		}
// 	}
//
// 	~Flat() { delete[] humans; }
// };
//
// void Flat::resize(int newCount) {
// 	Human* humansNew = new Human[newCount];
// 	for (int i = 0; i < count; i++) {
// 		humansNew[i] = humans[i];
// 	}
//
// 	delete[] humans;
// 	humans = humansNew;
// 	count = newCount;
// }
//
//
// class House{
// private:
// 	Flat* flats;
// 	int houseNumber;
// 	int houseCount;
//
// public:
// 	House(int num) : flats{ nullptr }, houseNumber{ num }, houseCount({ 0 }) {}
//
// 	House(const House& obj) {
// 		houseCount = obj.houseCount;
// 		houseNumber = obj.houseNumber;
// 		flats = new Flat[houseCount];
// 		for (int i = 0; i < houseCount; i++) flats[i] = obj.flats[i];
// 	}
//
// 	House& operator=(const House& obj) {
// 		if (&obj == this){ return *this; }
// 		delete[] flats;
//
// 		this->houseCount = obj.houseCount;
// 		this->houseNumber = obj.houseNumber;
//
// 		flats = new Flat[houseCount];
// 		for (int i = 0; i < houseCount; i++)
// 			flats[i] = obj.flats[i];
//
// 		return *this;
// 	};
//
//     House& addFlat(const Flat& f) {
//         resize(houseCount + 1);
//         flats[houseCount - 1] = f;
//         return *this;
//     }
//
// 	void setNumber(int num) { houseNumber = num; }
// 	void resize(int newCount);
// 	int getCount() const {return houseCount;}
//
//     void print() const {
//         cout << "\n=========================================" << endl;
//         cout << "HOUSE #" << houseNumber << endl;
//         cout << "=========================================" << endl;
//         for (int i = 0; i < houseCount; i++) {
//             cout << "Flat details:" << endl;;
//             flats[i].print();
//             cout << "-----------------------------------------" << endl;
//         }
//     }
//
// 	~House() { delete[] flats; }
// };
//
// void House::resize(int newCount) {
// 	Flat* houseNew = new Flat[newCount];
// 	for (int i = 0; i < houseCount; i++) {
// 		houseNew[i] = flats[i];
// 	}
//
// 	delete[] flats;
// 	flats = houseNew;
// 	houseCount = newCount;
// }
//
//
//
// int main() {
//
// 	setlocale(LC_ALL, "");
//
// 	cout << "\t My House \n\n";
//
// 	Human human1{};
// 	human1.input();
//
// 	Human human2{"Piter", "Parker", "0930001112", 23 };
// 	human2.print();
//
// 	cout << "\n-------------------------\n";
//
// 	Human human3{human1}; // copy
// 	human3.setAge(33);
// 	human3.print();
//
// 	cout << "\n-------------------------\n";
//
// 	Flat flat1{};
// 	flat1.setNumber(1);
// 	flat1.add(human1);
// 	flat1.add(human2);
// 	flat1.add();	// new human, human.input();
// 	cout << "\t Humans in flat 1: " << flat1.getCount() << '\n';
//
// 	Flat flat2{5};
// 	flat2.add();	// ...
// 	cout << "\t Humans in flat 2: " << flat2.getCount() << '\n';
//
// 	Flat flat3{flat2};	// copy
// 	flat3.setNumber(7);
// 	flat3.add(human3);
// 	flat3.add(human2);
//
// 	cout << "\t Humans in flat 3: " << flat3.getCount() << '\n';
// 	cout << "\n-------------------------\n";
//
// 	flat1.print();
// 	cout << "\n-------------------------\n";
// 	flat2.print();
// 	cout << "\n-------------------------\n";
// 	flat3.print();
// 	cout << "\n-------------------------\n";
//
// 	flat3.deliteIndex(1);
// 	flat3.print();
//
// 	House house1{15};
// 	house1.addFlat(flat1);
// 	house1.addFlat(flat2);
// 	house1.print();
// 	cout << "\t Flats in house: " << house1.getCount() << '\n';
// 	cout << "\n";
//
//
// 	House house2{ house1 };	// copy
// 	house2.setNumber(17);
// 	house2.print();
// 	cout << "\t Flats in house: " << house2.getCount() << '\n';
// 	cout << "\n";
//
// 	return 0;
// }
//
// // range() (end) (start, end)