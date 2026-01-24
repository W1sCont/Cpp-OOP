#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>

using std::cout;
using std::endl;
using std::cin;

enum types { Riva, Sea, Pool, Pond };	// const`s
const char* TypesName[] = { "Riva", "Sea", "Pool", "Pond" };

class Interface;

class Reservoir
{
    char* name;
    double width;
    double height;
    double deep;
    short type;	// !
public:
    Reservoir() : type{0}, name{nullptr}, width{0.0}, height{0.0}, deep{0.0} {}
    explicit Reservoir(const short type_) : type{ type_ }, name{ nullptr }, width{ 0.0 }, height{ 0.0 }, deep{ 0 } {}

    //... this->type

    ~Reservoir() { delete[] name; }

    Reservoir(const Reservoir& copy_) : type(copy_.type){
        name = nullptr;

        width = height = deep = 0;
        if (copy_.name != nullptr) {
            name = new char[strlen(copy_.name) + 1];
            strcpy(name, copy_.name);
        }
        width = copy_.width;
        height = copy_.height;
        deep = copy_.deep;
    }

    Reservoir& operator=(const Reservoir& obj) {
        if (this == &obj) return *this;

        delete[] name;

        if (obj.name != nullptr) {
            name = new char[strlen(obj.name) + 1];
            strcpy(name, obj.name);
        } else {
            name = nullptr;
        }

        width = obj.width;
        height = obj.height;
        deep = obj.deep;
        type = obj.type;

        return *this;
    }

    // ...

    void setType() {
        short t;
        cout << "Type (0-Riva, 1-Sea, 2-Pool, 3-Pond) > ";
        cin >> t;

        if (t >= 0 && t <= 3) {
            type = t;
            cout << "Type set to: " << TypesName[t] << "\n";
        } else {
            cout << "Invalid type! Set to Riva by default.\n";
            type = 0;
        }
    }

    const char* getType() { return TypesName[type]; }

    void check(double& data) {
        if (!cin.good()) {
            cout << "Invalid input. Set to 1 by default.\n";
            data = 1;
            cin.clear();
            cin.ignore(100, '\n');
        }
    }

    void setData() {

        char buffer[100];

        cout << "Name > ";
        cin.ignore();
        cin.getline(buffer, 100);

        delete[] name;
        name = new char[strlen(buffer) + 1];
        strcpy(name, buffer);

        cout << "Width > ";
        cin >> width;
        check(width);

        cout << "Height > ";
        cin >> height;
        check(height);

        cout << "Deep > ";
        cin >> deep;
        check(deep);
    }

    double volume() const { return width * height * deep; }
    double area() const { return width * height; }

    bool isSameType(const Reservoir& obj) const {
        if (this->type == obj.type)
            return true;
        else {
            return false;
        }
    }

    Reservoir isResAreaBiggest(const Reservoir& obj) const {
        if (this->type != obj.type) {
            cout << "Cannot compare - different types!\n";
            return *this;
        }

        return this->area() > obj.area() ? *this : obj;
    }


    friend Interface;
};

// Reservoir::Reservoir(...)



class Interface
{
    Reservoir* res;
    int size;
public:
    Interface() : res{ nullptr }, size{ 0 } {}

    void add() {
        Reservoir* temp = new Reservoir[size + 1];

        for (int i = 0; i < size; ++i) {
            temp[i] = res[i];
        }

        temp[size].setType();
        temp[size].setData();

        delete[] res;
        res = temp;
        ++size;

    }
    void del() {
        if (size == 0) {
            cout << "Nothing to delete!\n";
            return;
        }

        int num{};
        cout << "Del index > ";
        cin >> num;
        if (num >= size || num < 0) {
            cout << "Invalid index!\n";
            return;
        }

        Reservoir* temp = new Reservoir[size - 1];
        for (int i = 0, j = 0; i < size; ++i) {
            if (i == num) continue;
            temp[j] = res[i];
            j++;
        }

        delete[] res;
        res = temp;
        --size;
        cout << "Deleted!\n";
    }

    void print() const {
        if (size == 0) {
            cout << "Empty!\n";
            return;
        }

        for (int i = 0; i < size; ++i) {
            cout << i << ". "
                 << (res[i].name ? res[i].name : "N/A") << " | "
                 << res[i].getType() << " | "
                 << "W:" << res[i].width << " "
                 << "H:" << res[i].height << " "
                 << "D:" << res[i].deep << "\n";
        }
    }

    void showDetails() {
        if (size == 0) return;

        int idx;
        cout << "Index: ";
        cin >> idx;

        if (idx >= 0 && idx < size) {
            cout << "\n=== Details ===\n";
            cout << "Name: " << (res[idx].name ? res[idx].name : "N/A") << "\n";
            cout << "Type: " << TypesName[res[idx].type] << "\n";
            cout << "Area: " << res[idx].area() << "\n";
            cout << "Volume: " << res[idx].volume() << "\n";
        }
    }

    void editRes() {
        int ind;
        cout << "Enter index to change data: ";
        cin >> ind;
        if (ind >= size || ind < 0)
            cout << "Invalid indices!\n";

        res[ind].setData();
    }

    void compareReservoirs() const {
        if (size < 2) {
            cout << "Need at least 2 reservoirs!\n";
            return;
        }

        int ind1, ind2;
        cout << "Enter first index: ";
        cin >> ind1;
        cout << "Enter second index: ";
        cin >> ind2;

        if (ind1 < 0 || ind1 >= size || ind2 < 0 || ind2 >= size) {
            cout << "Invalid indices!\n";
            return;
        }

        if (res[ind1].isSameType(res[ind2])) {
            cout << "Same type: " << res[ind1].getType() << "\n";

            const Reservoir& bigger = res[ind1].isResAreaBiggest(res[ind2]);
            cout << "Larger reservoir: " << (bigger.name ? bigger.name : "N/A") << "\n";
        } else {
            cout << "Different types!\n";
        }
    }
    // ...
    ~Interface(){ delete[] res; }

};

int main()
{
    setlocale(LC_ALL, "");
    Interface manag{};

    // while ... getch ... switch ...
    while(true) {
        cout << "1-Add 2-Del 3-Print 4-Comparative 5-Edit 6-Show details 0-Exit\n> ";
        int choice;
        cin >> choice;

        if (choice == 0) break;
        switch(choice) {
            case(1):
                manag.add();
                break;
            case(2):
                manag.del();
                break;
            case(3):
                manag.print();
                break;
            case(4):
                manag.compareReservoirs();
                break;
            case(5):
                manag.editRes();
                break;
            case(6):
                manag.showDetails();
                break;
            default:
                cout << "Error \n";
        }
    }

    cout << TypesName[Riva] << endl;	//

    return 0;
}