#include <iostream>
using namespace std;

class Base {
public:
    Base() { 
        cout << "Base constructor\n";
        show();   // virtual call inside constructor
    }
    virtual void show() { cout << "Base show()\n"; }
};

class Derived : public Base {
public:
    Derived() { cout << "Derived constructor\n"; }
    void show() override { cout << "Derived show()\n"; }
};

int main() {
    Derived d;
    return 0;
}