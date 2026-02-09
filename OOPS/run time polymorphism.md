#include <iostream>
using namespace std;

class Shape {
public:
    virtual void draw() {
        cout << "Drawing a generic shape" << endl;
    }

    // FIX 3: Always add a Virtual Destructor in Polymorphism
    // This ensures the Child's destructor is called before the Base's.
    virtual ~Shape() {
        cout << "Shape Destroyed" << endl;
    }
};

class Circle : public Shape {
public:
    void draw() override {
        cout << "Drawing a Circle" << endl;
    }
    
    // Optional: Just to show it works
    ~Circle() { cout << "Circle Destroyed" << endl; }
};

class Rectangle : public Shape {
public:
    void draw() override {
        cout << "Drawing a Rectangle" << endl;
    }
    ~Rectangle() { cout << "Rectangle Destroyed" << endl; }
};

int main() {
    // FIX 1: Initialize pointer to nullptr for safety
    Shape* s = new Shape(); 
    s->draw();
    // Don't call s->draw() here! s is null/empty.
    delete s;
    // 1. Pointing to a Circle
    s = new Circle();
    s->draw(); 

    // FIX 2: Delete the old object before creating a new one
    delete s; // Calls ~Circle() then ~Shape()
    cout << "--- Switching Shapes ---" << endl;

    // 2. Pointing to a Rectangle
    s = new Rectangle();
    s->draw(); 

    // FIX 2: Delete the final object before program ends
    delete s; // Calls ~Rectangle() then ~Shape()

    return 0;
}