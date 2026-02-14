#include <iostream>
#include <string>

using std::cout;
using std::string;


class Bolt
{
protected:
    int diameter;
public:
    explicit Bolt(int d = 8) : diameter{ d } { cout << "Bolt constructor\n"; }
    virtual ~Bolt() { cout << "Bolt destructor\n"; }
    int getDiameter() const { return diameter; }
    void setDiameter(int d) { diameter = d; }
    void print() const { cout << "Bolt diameter: " << diameter << "\n\n"; }
};


// ...  Wheels, Engine, Doors ...+-
class Wheels {
protected:
    int radius;
    Bolt bolt;
public:
    Wheels() : radius{ 19 }, bolt{ 12 } { cout << "Wheels constructor\n"; }
    explicit Wheels(int radius_) : radius{ radius_ }, bolt{ 15 } { cout << "Wheels constructor\n"; }
    virtual ~Wheels() {cout << "Wheels destructor\n";}

    int getRadius() const { return radius; }

    virtual void print() const {
        cout << "Wheels radius: " << radius << '\n';
        bolt.print();
    }
};

class Engine {
protected:
    int power;
    Bolt bolt;
public:
    Engine() : power{ 150 } { cout << "Engin constructor\n"; } // 150 HP = 111kW
    explicit Engine(int power_) : power{ power_ }, bolt{ 14 }  { cout << "Engin constructor\n"; }
    virtual ~Engine() { cout << "Engin destructor\n"; }

    int getPower() const { return power; }
    void setBoltSize(int d) { bolt.setDiameter(d); }

    virtual void print() const {
        cout << "Engine power: " << power << '\n';
        bolt.print();
    }
};

class Doors {
protected:
    string side;
    Bolt bolt;
public:
    Doors() : side {"1right 1left" } { cout << "Doors constructor\n"; }
    explicit Doors(string side_) : side{ side_ }, bolt{ 13 }  { cout << "Doors constructor\n"; }
    virtual ~Doors() { cout << "Doors destructor\n"; }

    string getSide() const { return side; }
    void setBoltSize(int d) { bolt.setDiameter(d); }
    virtual void print() const {
        cout << "Doors side: " << side << '\n';
        bolt.print();
    }
};

class Car : public Bolt, public Wheels, public Engine, public Doors
{
protected:
    string type;
    Bolt bolt;
public:
    Car() : type{ "diesel" } { cout << "Car constructor\n"; }
    Car(string type_, int radius_, int power_, string side_ )
        : type{ type_ }, Wheels{ radius_ }, Engine(power_), Doors{ side_ }, bolt{ 12 } { cout << "Car constructor\n"; }
    ~Car() override { cout << "Car destructor\n"; }

    string getType() const { return type; }


    void print() const override {
        cout << "\n--- Full Car Info (" << type << ") ---\n";
        Wheels::print();
        Engine::print();
        Doors::print();
        cout << "Car own mounting: ";
        bolt.print();
    }
};


int main()
{
    Bolt b(10);		// test
    cout << "Bolt " << b.getDiameter() << "\n\n";

    Car tesla{"electro", 22, 155, "2left 2right", };
    cout << "\n============\n";
    cout << "My car tesla: \n";
    tesla.print();

    Car passat{};		// ( parameters... )
    cout << "\n============\n";
    cout << "My car ww passat: \n";
    passat.print();

    return 0;
}