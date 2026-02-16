// Shape

#include <iostream>
#include <cmath>
using namespace std;

class Shape {
protected:
    int x, y;
public:
    virtual void Input() = 0;
    virtual void Show() const = 0;
    virtual void Draw() const = 0;
    virtual ~Shape() = default;
};

class Square : public Shape {
private:
    int side;
public:
    void Input() override {
        cout << "Enter square - x/y and side length : ";
        cin >> x >> y >> side;
    }

    void Show() const override {
        cout << "Square top left: (" << x << ", " << y << ") side length: " << side << endl;
    }

    void Draw() const override {
        for (int i{}; i < side + y; ++i) {
            if (i < y) cout << " ";
            else {
                for (int j{}; j < side + x; ++j) {
                    if (j < x) cout << "  ";
                    else cout << " * ";
                }
            }
            cout << endl;
        }
    }
};

class RectangleShape : public Shape {
private:
    int width, height;

public:
    void Input() override {
        cout << "Enter rectangle x/y, width and height): ";
        cin >> x >> y >> width >> height;
    }

    void Show() const override {
        cout << "Rectangle top left: (" << x << ", " << y << ") width : " << width << ", height: " << height << endl;
    }

    void Draw() const override {
        for (int i{}; i < height + y; ++i) {
            if (i < y) cout << " ";
            else {
                for (int j{}; j < width + x; ++j) {
                    if (j < x) cout << "  ";
                    else cout << " * ";
                }
            }
            cout << endl;
        }
    }
};

class Circle : public Shape {
private:
    int radius;

public:
    void Input() override {
        cout << "Enter Circle x/y and radius: ";
        cin >> x >> y >> radius;
    }

    void Show() const override {
        cout << "Circle center: (" << x << ", " << y << ") radius: " << radius << endl;
    }

    void Draw() const override {
        for (int i{}; i < y; ++i) cout << '\n';

        for (int y = radius; y >= -radius; --y) {
            for (int s{}; s < x; ++s) cout << " ";
            for (int x = -radius; x <= radius; ++x)
                if (sqrt(x*x + y*y) <= radius-1)
                    cout << "* ";
                else
                    cout << "  ";
            cout << "\n";
        }
    }
};

class EllipseShape : public Shape {
private:
    int width, height;

public:
    void Input() override {
        cout << "Enter elipse x/y, width and length: ";
        cin >> x >> y >> width >> height;
    }

    void Show() const override {
        cout << "Elipse bounding rectangle top left: (" << x << ", " << y << ") width: " << width << ", height: " << height << endl;
    }

    void Draw() const override {
        int a = width / 2;
        int b = height / 2;

        for (int i{}; i < y; ++i) cout << '\n';

        for (int i = b; i >= -b; --i) {
            for (int s{}; s < x; ++s) cout << " ";
            for (int j = -a; j <= a; ++j) {
                if ((double)(j*j)/(a*a) + (double)(i*i)/(b*b) <= 1)
                    cout << "* ";
                else
                    cout << "  ";
            }
            cout << "\n";
        }
    }
};

int main() {
    const int shapeCount = 4;
    Shape* shapes[shapeCount];
    shapes[0] = new Square();
    shapes[1] = new RectangleShape();
    shapes[2] = new Circle();
    shapes[3] = new EllipseShape();

    for (int i = 0; i < shapeCount; ++i) {
        cout << "Input detail for shape " << i + 1 << ":\n";
        shapes[i]->Input();
    }

    for (int i = 0; i < shapeCount; ++i) {
        shapes[i]->Show();
        shapes[i]->Draw();
        cout << "Shape " << i + 1 << " drawn\n";
    }

    for (int i = 0; i < shapeCount; ++i) {
        delete shapes[i];
    }

    return 0;
}