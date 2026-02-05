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
// class Array {
// private:
//     int Size;
//     int* arr;
// public:
//     Array() : Size{1}, arr{new int[Size]{}} {
//         cout << "Default constructor\n";
//     }
//
//     explicit Array(int size_) : Size{size_ > 0 ? size_ : 1} {
//         arr = new int[Size]{};
//         cout << "Size constructor\n";
//     }
//
//     Array(const int* arr_, int size_) : Size{size_ > 0 ? size_ : 1}  {
//         arr = new int[Size]{};
//
//         for (int i{0}; i < Size; ++i) {
//             arr[i] = arr_[i];
//         }
//
//         cout << "Array constructor\n";
//     }
//
//     ~Array() {
//         delete[] arr;
//         cout << "Destructor\n";
//     }
//
//     Array(const Array& copy_) : Size{copy_.Size} {
//         arr = new int[Size];
//         for (int i = 0; i < Size; ++i) {
//             arr[i] = copy_.arr[i];
//         }
//         cout << "Copy constructor\n";
//     }
//
//
//     Array& operator=(const Array& copy_) {
//         if (this == &copy_) return *this;
//
//         delete[] arr;
//
//         Size = copy_.Size;
//         arr = new int[Size];
//
//         for (int i = 0; i < Size; ++i) {
//             arr[i] = copy_.arr[i];
//         }
//
//         cout << "Copy assignment\n";
//         return *this;
//     }
//
//     Array(Array&& other) noexcept : Size{other.Size}, arr{other.arr} {
//         other.arr = nullptr;
//         other.Size = 0;
//         cout << "Move constructor\n";
//     }
//
//     int getSize() const { return Size; }
//
//     void randValue() {
//         for (int i{0}; i < this->Size; ++i) {
//             arr[i] = rand() % 10;
//         }
//     }
//
//     void print() const {
//         for (int i = 0; i < Size; ++i) {
//             cout << arr[i] << " ";
//         }
//         cout << endl;
//     }
// };
//
//
//
// int main() {
//     setlocale(LC_ALL, "");
//     srand(time(nullptr));
//
//     Array arr{};
//     arr.print();
//     Array arr2(5);
//     arr2.randValue();
//     arr2.print();
//
//     Array arr3 = arr2;
//     arr3.print();
//
//     Array arr4 = std::move(arr2);
//     arr4.print();
//     return 0;
// }
