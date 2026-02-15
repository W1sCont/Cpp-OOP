#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;


class Bolt
{
protected:
    int diameter;
public:
    explicit Bolt(int d = 8) : diameter{ d } { cout << "Bolt constructor\n"; }
    ~Bolt() { cout << "Bolt destructor\n"; }
    virtual int getDiameter() const { return diameter; }
    virtual void print() const {
        cout << "Bolt diameter: " << diameter << "\n\n";
    }
};


// ...  Wheels, Engine, Doors ...+-
class Wheels : virtual public Bolt{
protected:
    int radius;
public:
    Wheels() = delete;
    Wheels(int radius_, int b) : radius{ radius_ }, Bolt{ b } { cout << "Wheels constructor\n"; }
    ~Wheels() {cout << "Wheels destructor\n";}

    int getRadius() const { return radius; }

    virtual void print() const {
        cout << "Wheels radius: " << radius << '\n';
        Bolt::print();
    }
};

class Engine : virtual public Bolt{
protected:
    int power;
public:
    Engine() = delete;
    Engine(int power_, int b) : power{ power_ }, Bolt{ b } { cout << "Engin constructor\n"; }
    ~Engine() { cout << "Engin destructor\n"; }

    int getPower() const { return power; }

    virtual void print() const {
        cout << "Engine power: " << power << '\n';
        Bolt::print();
    }
};

class Doors : virtual public Bolt {
protected:
    string side;
public:
    Doors() = delete;
    Doors(string side_, int b) : side{ side_ }, Bolt{ b }  { cout << "Doors constructor\n"; }
    ~Doors() { cout << "Doors destructor\n"; }

    string getSide() const { return side; }

    virtual void print() const {
        cout << "Doors side: " << side << '\n';
        Bolt::print();
    }
};

class Car :  public Wheels, public Engine, public Doors
{
protected:
    string type;
public:
    Car() : type{ "diesel" }, Wheels{17, 0}, Engine{152, 0}, Doors{"1right 1 left", 0}, Bolt{ 16 } { cout << "Car constructor\n"; }
    Car(string type_, int radius_, int power_, string side_, int b )
        : type{ type_ }, Wheels{ radius_, 0 }, Engine(power_, 0), Doors{ side_, 0 }, Bolt{ b } { cout << "Car constructor\n"; }
    ~Car() { cout << "Car destructor\n"; }

    string getType() const { return type; }
    int getDiameter() const override { return diameter; }


    void print() const override {
        cout << "\n--- Full Car Info (" << type << ") ---\n";
        cout << "Wheels: ";
        Wheels::print();
        cout << "Engine: ";
        Engine::print();
        cout << "Doors: ";
        Doors::print();
        cout << "Car own mounting:\n";
        Bolt::print();
    }

};


int main()
{
    // Bolt b(10);		// test
    // cout << "Bolt " << b.getDiameter() << "\n\n";

    Car tesla{"electro", 22, 155, "2left 2right", 23 };
    cout << "\n============\n";
    cout << "My car tesla: \n";
    tesla.print();

    Car passat{};		// ( parameters... )
    cout << "\n============\n";
    cout << "My car ww passat: \n";
    passat.print();


    return 0;
}