#include <iostream>
#include <iomanip>
// #include <conio.h>
#include <cmath>
#include <limits>

using namespace std;


// nsd - recursive !!!

class Fractal
{
private:
    int ch;
    int zn;

    int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
    }

    void minim() {
        int temp = gcd(abs(ch), abs(zn));
        ch /= temp;
        zn /= temp;

        if (zn < 0) {
            ch = -ch;
            zn = -zn;
        }
    }

public:
    Fractal() {						// constructor
        ch = 0;
        zn = 1;
        cout << "Constructor w/out params \n";
    }

    Fractal(int ch_, int zn_)		// constructor
    {
        ch = ch_;
        zn = zn_;
        if (zn == 0) {
            zn = 1;
            cout << "zn cant be 0" << endl;
        }
        minim();
        // cout << "Constructor w/ params \n";
    }

    void setFract(int ch_, int zn_)
    {
        ch = ch_;
        zn = zn_;
        if (zn == 0) {
            zn = 1;
            cout << "zn cant be 0" << endl;
        }
        minim();
    }

    int getCh() { return ch; }

    int getZn() { return zn; }

    void print() { cout << ch << "/" << zn << endl; }

    ~Fractal() {
       // cout << "Destructor \n";
    }


    void input();// +++


    Fractal add(Fractal f1, Fractal f2);

    Fractal sub(Fractal f1, Fractal f2);

    Fractal mul(Fractal f1, Fractal f2);

    Fractal div(Fractal f1, Fractal f2);

    Fractal operator+(const Fractal& f2) const {
        Fractal rez{ ch * f2.zn + f2.ch * zn, zn * f2.zn };
        return rez;
    }

    Fractal operator-(const Fractal& f2) const {
        Fractal rez{ ch * f2.zn - f2.ch * zn, zn * f2.zn };
        return rez;
    }

    Fractal operator*(const Fractal& f2) const {
        Fractal rez{ ch * f2.ch, zn * f2.zn };
        return rez;
    }

    Fractal operator/(const Fractal& f2) const {
        if (f2.ch == 0) {
            cout << "Zero division, return 0/1" << endl;
            return Fractal(0, 1);
        }

        Fractal rez{};
        rez.ch = this->ch * f2.zn;
        rez.zn = this->zn * f2.ch;

        rez.minim();
        return rez;

    }

};

Fractal Fractal::add(Fractal f1, Fractal f2)
{
    Fractal rez{};

    rez.ch = f1.ch * f2.zn + f2.ch * f1.zn;
    rez.zn = f1.zn * f2.zn;

    rez.minim();
    return rez;
}

Fractal Fractal::sub(Fractal f1, Fractal f2)
{
    Fractal rez{};

    rez.ch = f1.ch * f2.zn - f2.ch * f1.zn;
    rez.zn = f1.zn * f2.zn;

    rez.minim();
    return rez;
}

Fractal Fractal::mul(Fractal f1, Fractal f2)
{
    Fractal rez{};

    rez.ch = f1.ch * f2.ch;
    rez.zn = f1.zn * f2.zn;

    rez.minim();
    return rez;
}

Fractal Fractal::div(Fractal f1, Fractal f2)
{
    if (f2.ch == 0) {
        cout << "Zero division, return 0/1" << endl;
        return Fractal(0, 1);
    }

    Fractal rez{};

    rez.ch = f1.ch * f2.zn;
    rez.zn = f1.zn * f2.ch;

    rez.minim();
    return rez;
}


void Fractal::input()
{
    while(!(cin >> ch)) {
        cout << "Incorrect data, try again: ";
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    cin.ignore(1);

    while(!(cin >> zn)) {
        cout << "Incorrect data, try again: ";
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    if (zn == 0) {
        zn = 1;	 std::cout << "zn <- 1\n";
    }
}

int main()
{
    setlocale(LC_ALL, "");

    cout << "Fractals:" << endl << endl;

    Fractal f1{}, f2{ 1, 2 }, f3{};		// Objects
    char op{};

    while (op != 'e') {
        cout << "f1> ";
        f1.input();

        cout << "f2> ";
        f2.input();

        cout << "+-*/ or 'e' for end \n";
        cin >> op;
        while(op != '+' && op != '-' && op != '*' && op != '/' && op != 'e') {
            cout << "Incorrect data, try again: ";
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cin >> op;
        }

        switch (op) {
            case '+':
                // f3 = f3.add(f1, f2);
                f3 = f1 + f2;
                f3.print();
                cout << "\n";
                break;
            case '-':
                // f3 = f3.sub(f1, f2);
                f3 = f1 - f2;
                f3.print();
                cout << "\n";
                break;
            case '*':
                // f3 = f3.mul(f1, f2);
                f3 = f1 * f2;
                f3.print();
                cout << "\n";
                break;
            case '/':
                // f3 = f3.div(f1, f2);
                f3 = f1 / f2;
                f3.print();
                cout << "\n";
                break;
            case 'e':
                break;
            default:
                cout << "incorrect data" << endl;
                cout << "+-*/ or 'e' for end \n";
                cin >> op;
        }
    }

    cout << "Фінальний чисельник: " << f3.getCh() << endl;
    cout << "Фінальний знаменник: " << f3.getZn() << endl;
    return 0;
}