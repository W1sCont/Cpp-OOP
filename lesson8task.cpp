#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <iomanip>
#include <cstring>

using std::cin;
using std::cout;
using std::endl;

template <typename T,  int row_, int col_>
class Matrix {
private:
    int row;
    int col;
    T** arr;
public:
    Matrix() : row{row_}, col{col_} {
        arr = new T*[row];
        for (int i{0}; i < row; ++i) {
            arr[i] = new T[col]{};
        }
    }

    Matrix(const Matrix& other) : row{row_}, col{col_} {
        arr = new T*[row];
        for (int i = 0; i < row; ++i) {
            arr[i] = new T[col];
        }

        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                arr[i][j] = other.arr[i][j];
            }
        }
    }

    Matrix& operator=(const Matrix& obj) {
        if (this == &obj) return *this;

        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                arr[i][j] = obj.arr[i][j];
            }
        }
        return *this;
    }

    ~Matrix() {
        for (int i{0}; i < row; ++i) {
            delete[] arr[i];
        }
        delete[] arr;
    }



    int getRows() const { return row; }
    int getCols() const { return col; }

    T getElem() {
        int rows_, cols_;
        cout << "Enter row and col to get element > " << endl;
        while (!(cin >> rows_ >> cols_) || rows_ < 0 || rows_ >= row || cols_ < 0 || cols_ >= col) {
            cout << "Invalid coordinates! Try again > " << endl;
            cin.clear();
            cin.ignore(100, '\n');
        }

        return arr[rows_][cols_];
    }

    void setRand() {
        for (int i{0}; i < row; ++i) {
            for (int j{0}; j < col; ++j)
            arr[i][j] =  rand() % 50 + 10;
        }
    }

    T maxEl() {
        T max = arr[0][0];
        for (int i{0}; i < row; ++i) {
            for (int j{0}; j < col; ++j){
                if (max < arr[i][j]) max = arr[i][j];
            }
        }
        return max;
    }

    T minEl() {
        T min = arr[0][0];
        for (int i{0}; i < row; ++i) {
            for (int j{0}; j < col; ++j) {
                if (min > arr[i][j]) min = arr[i][j];
            }
        }
        return min;
    }

    Matrix operator+(const Matrix& obj) const {
        Matrix result;
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                result.arr[i][j] = this->arr[i][j] + obj.arr[i][j];
            }
        }
        return result;
    }

    Matrix operator-(const Matrix& obj) const {
        Matrix result;
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                result.arr[i][j] = this->arr[i][j] - obj.arr[i][j];
            }
        }
        return result;
    }

    Matrix operator*(const Matrix& obj) const {
        Matrix result;
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                result.arr[i][j] = 0;
                for (int k = 0; k < col; ++k) {
                    result.arr[i][j] += this->arr[i][k] * obj.arr[k][j];
                }
            }
        }
        return result;
    }

    Matrix operator/(const Matrix& obj) const {
        Matrix result;
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (obj.arr[i][j] != 0) {
                    result.arr[i][j] = this->arr[i][j] / obj.arr[i][j];
                } else {
                    result.arr[i][j] = 0;
                }
            }
        }
        return result;
    }

    friend std::ostream& operator<<(std::ostream& os, const Matrix& obj) {
        for (int i = 0; i < row_; ++i) {
            for (int j = 0; j < col_; ++j) {
                os << std::setw(4) << obj.arr[i][j] << " ";
            }
            os << "\n";
        }
        return os;
    }

    friend std::istream& operator>>(std::istream& is, Matrix& obj) {
        for (int i = 0; i < row_; ++i) {
            for (int j = 0; j < col_; ++j) {

                if (!(is >> obj.arr[i][j])) {
                    is.clear();
                    is.ignore(100, '\n');
                    obj.arr[i][j] = T{};
                }
            }
        }
        return is;
    }


};



int main() {
    setlocale(LC_ALL, "");
    srand(time(nullptr));

    const int Row = 2, Col  = 2;
    Matrix<int, Row, Col> a{};
    Matrix<int, Row, Col> b{};
    Matrix<int, Row, Col> c{};

    a.setRand();
    cout << a;
    cout << "Max el: " << a.maxEl() << endl;
    cout << "Min el: " << a.minEl() << endl;

    cout << "Enter " << Row << " & " << Col << " elements:\n";
    cin >> a;
    cout << a;
    cout << '\n';
    b.setRand();
    cout << b;

    c = a + b;
    cout << '+' << endl;
    cout << c;
    c = a - b;
    cout << '-' << endl;
    cout << c;
    c = a * b;
    cout << '*' << endl;
    cout << c;
    c = a / b;
    cout << '/' << endl;
    cout << c;


    // cout << a.getElem() << endl;

    return 0;
}