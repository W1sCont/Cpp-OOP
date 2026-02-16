#include <iostream>

using std::cout;;

template<class T>
class Auto_ptr_m
{
    T* m_ptr;
public:
    explicit Auto_ptr_m(T* ptr = nullptr) : m_ptr(ptr) { cout << "[Auto_ptr] constructor\n"; }
    ~Auto_ptr_m() { delete m_ptr; cout << "[Auto_ptr] destroyed\n";}

    T& operator*() const { return *m_ptr; }
    T* operator->() const { return m_ptr; }
};

template<class T>
class Unique_ptr {
    T* m_ptr;
public:
    explicit Unique_ptr(T* ptr = nullptr) : m_ptr(ptr) { cout << "[Unique_ptr] constructor\n"; }
    ~Unique_ptr() { delete m_ptr; cout << "[Unique_ptr] destroyed\n"; }

    Unique_ptr(const Unique_ptr& ptr) = delete;
    Unique_ptr& operator=(Unique_ptr& ptr) = delete;

    // m.c
    Unique_ptr(Unique_ptr&& c_ptr) noexcept {
        m_ptr = c_ptr.m_ptr;
        c_ptr.m_ptr =nullptr;
        cout << "[Unique_ptr] move constructor\n";
    }

    T& operator*() const { return *m_ptr; }
    T* operator->() const { return m_ptr; }
};

template<class T>
class Shared_ptr {
    T* m_ptr;
    int* count;
public:
    explicit Shared_ptr(T* ptr = nullptr)
        : m_ptr{ptr} { count = new int{ 1 }; cout << "[Shared_ptr] constructor, count=" << *count << "\n"; }

    ~Shared_ptr()
    {
        if (!count) return;

        --(*count);
        cout << "[Shared_ptr] destructor, count=" << *count << "\n";

        if (*count == 0) {
            delete m_ptr;
            delete count;
            cout << "[Shared_ptr] resource deleted\n";
        }
    }

    // c.c.
    Shared_ptr(const Shared_ptr& c_ptr) {
        count = c_ptr.count;
        m_ptr = c_ptr.m_ptr;
        if (count) {
            ++(*count);
        }
        cout << "[Shared_ptr] copy constructor, count=" << *count << "\n";
    }

    // =
    Shared_ptr& operator=(const Shared_ptr& c_ptr) {
        if (&c_ptr == this) return *this;
        if (count) {
            --(*count);
            if (*count == 0) {
                delete m_ptr;
                delete count;
            }
        }

        m_ptr = c_ptr.m_ptr;
        count = c_ptr.count;
        if (count) {
            ++(*count);
        }
        return *this;
    }

    T& operator*() const { return *m_ptr; }
    T* operator->() const { return m_ptr; }
};

// Пример класса, чтобы доказать, что это работает
class Resource
{
public:
    Resource() { cout << "Resource acquired\n"; }
    ~Resource() { cout << "Resource destroyed\n"; }
    void sayHi() const { cout << "Hi!\n"; }
};

void someFunction()
{
    Auto_ptr_m<Resource> ptr(new Resource());
    ptr->sayHi();
}

void SharedTest()
{
    Shared_ptr<Resource> ptr(new Resource());
    ptr->sayHi();
    Shared_ptr<Resource> s1 = ptr;
    Shared_ptr<Resource> s2 = ptr;
    Shared_ptr<Resource> s3 = s2;
    s3->sayHi();
}

void UniqueTest()
{
    Unique_ptr<Resource> ptr(new Resource());
    ptr->sayHi();
    Unique_ptr<Resource> u1(std::move(ptr));
    u1->sayHi();
    // u1 = ptr; // error
}

int main()
{
    cout << "\nAuto_ptr: \n";
    someFunction();
    // Auto_ptr_m<Resource> res1(new Resource());
    // Auto_ptr_m<Resource> res2(res1);				// ay-ya-ya!!!

    cout << "\nShared_ptr: \n";
    SharedTest();

    cout << "\nUniq_ptr: \n";
    UniqueTest();

    return 0;
}