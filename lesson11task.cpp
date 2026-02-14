#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

const char* types[]{ "4legs", "birds", "fish" };
enum petType { FourLegs, Bird, Fish };

class Pet {
protected:
    string name;
    string voice;
    int age;
public:
    Pet() : name{"Pet"}, voice{"???"}, age{ 0 } {}
    Pet(string name_, string voice_, int age_) : name{ name_ }, voice{ voice_ }, age{age_} { cout << "Pet constructor\n"; }
    ~Pet() { cout << "Pet destructor\n"; }

    void showInfo() const{
        cout << "Pet " << name << " Age: " << age << endl;
    }
    void input() {
        cout << "Enter name: ";
        getline(cin, name);
        cin.ignore(1000, '\n');

        cout << "Enter age: ";
        cin >> age;
        if (cin.fail()) {
            cout << "Invalid age, default 1\n";
            age = 1;
        }
    }

    string getName() const{ return name; }
    int getAge() const{ return age; }
    string getVoice() { return voice; }
};

class Kind : public Pet
{
protected:
    int type;
    string breed;
    string color;
public:
    Kind(string name_, string voice_, int age_, int type_, string breed_) : Pet(name_, voice_, age_), type{ type_ }, breed{ breed_ }
    {
        cout << "Kind constructor\n";
    }

    Kind() : Pet("--","--", 0), type{ 0 } {}

    const char* getType() const { return types[type]; }
    string getBreed() const { return breed; }

    ~Kind()
    {
        cout << "Kind destructor\n";
    };
};


class Dog : public Kind {
private:
    string color;
public:
    Dog() : Kind("Dog","gav", 0, FourLegs, "PitBul"), color{"Brown"} { cout << "Dog constructor\n"; }
    Dog(string name_, string voice_, int age_, int type_, string breed_, string color_)
        : Kind(name_, voice_, age_, type_, breed_), color{ color_ } { cout << "Dog constructor\n"; }
    ~Dog() { cout << "Dog destructor\n"; }

    string getName() const{ return name; }
    int getAge() const{ return age; }
    string getVoice() const { return voice; }
    string getColor() const { return color; }

    void showInfo() const{
        cout << "\n" << "Name: " << getName() << ",  say: " << getVoice() << ", age: " << getAge() << "\n";
        cout << "Type: " << getType() << ", breed: " << getBreed() << ",  color: " << getColor() << "\n\n";
    }
};

class Cat : public Kind {
private:
    string coat;
public:
    Cat() : Kind("Cat","meow", 0, FourLegs, "Siam"), coat{"short"} { cout << "Cat constructor\n"; }
    Cat(string name_, string voice_, int age_, int type_, string breed_, string coat_)
        : Kind(name_, voice_, age_, type_, breed_), coat{ coat_ } { cout << "Cat constructor\n"; }
    ~Cat() { cout << "Cat destructor\n"; }

    string getName() const{ return name; }
    int getAge() const{ return age; }
    string getVoice() const { return voice; }
    string getCoat() const { return coat; }

    void showInfo() const{
        cout << "\n" << "Name: " << getName() << ",  say: " << getVoice() << ", age: " << getAge() << "\n";
        cout << "Type: " << getType() << ", breed: " << getBreed() << ",  coat: " << getCoat() << "\n\n";
    }
};

class Parrot : public Kind {
private:
    bool speak;
public:
    Parrot() : Kind("Parrot","To be or not to be", 0, Bird, " "), speak{ true } { cout << "Parrot constructor\n"; }
    Parrot(string name_, string voice_, int age_, int type_, string breed_ , bool speak_)
        : Kind(name_,voice_, age_, type_, breed_), speak{ speak_ } { cout << "Parrot constructor\n"; }
    ~Parrot() { cout << "Parrot destructor\n"; }

    string getName() const{ return name; }
    int getAge() const{ return age; }
    string getVoice() const { return voice; }

    void showInfo() const{
        cout << "\n" << "Name: " << getName() << ",  say: " << getVoice() << ", age: " << getAge() << "\n";
        cout << "type: " << getType() << ", breed: "<< getBreed() << ",  speak: " << (speak ? "yes" : "no")  << "\n\n";
    }
};

class MyFish : public Kind {
private:
    bool hunter;
public:
    MyFish() : Kind("Fish", "bul-bul", 0, Fish, "Gold"), hunter{ false } { cout << "Fish constructor\n"; }
    MyFish(string name_, string voice_, int age_, int type_, string breed_, bool hunter_)
        : Kind(name_,voice_, age_, type_, breed_), hunter{ hunter_ } { cout << "Fish constructor\n"; }
    ~MyFish() { cout << "Fish destructor\n"; }

    string getName() const{ return name; }
    int getAge() const{ return age; }
    string getVoice() const { return voice; }

    void showInfo() const{
        cout << "\n" << "Name: " << getName() << ",  say: " << getVoice() << ", age: " << getAge() << "\n";
        cout << "type: " << getType() << ", breed: "<< getBreed() << ",  hunter: " << (hunter ? "yes" : "no")  << "\n\n";
    }

    void input() {
        cout << "Enter name: ";
        getline(cin, name);
        if (name.empty()) {
            cout << "Default name Betti\n";
            name = "Betti";
        }

        cout << "Enter age: ";
        cin >> age;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid age, default 1\n";
            age = 1;
        }

        cout << "Enter 1 if fish type is hunter else enter 0: ";
        if (!(cin >> hunter) || (hunter != 1 && hunter != 0)) {
            cout << "Invalid number. Default 0\n";
            hunter = false;
        }
    }

    // not complete
};


int main() {
    setlocale(LC_ALL, "");

    // MyFish betti{};
    // betti.showInfo();
    // betti.input();
    // betti.showInfo();

    Dog d{ "Rodger", "Gav", 2, FourLegs, "Terier", "Brown" };

    // --- -> cout << d << "\n";
    cout << "\n" << "Name: " << d.getName() << ",  say: " << d.getVoice() << ", age: " << d.getAge() << "\n";
    cout << "Type: " << d.getType() << ", breed: " << d.getBreed() << ",  color: " << d.getColor() << "\n\n";

    Parrot aga{"Aga","ImAga", 2, Bird, "Cockatoo", true};
    aga.showInfo();

    MyFish nemo{};
    nemo.showInfo();

    Cat grey{};
    grey.showInfo();

    return 0;
}