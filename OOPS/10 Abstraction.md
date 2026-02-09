// Concept: Hiding unnecessary details and showing only the essential parts to the user.

// Implementation:

// Access Specifiers: Using public for the interface and private for internal logic.

// Abstract Classes: A class that cannot be instantiated (you can't make an object of it). It is designed to be a base class.

// Pure Virtual Functions: A function defined in a base class that has no implementation (e.g., virtual void draw() = 0;) and must be overridden by the child class. If a class has at least one pure virtual function, it becomes an Abstract Class.

class Shape { // Abstract Class
public:
    // Pure Virtual Function
    virtual void draw() = 0; 
};

class Circle : public Shape {
public:
    void draw() override {
        cout << "Drawing Circle" << endl;
    }
};

int main() {
    // Shape s; // ERROR: Cannot instantiate abstract class
    Shape* s = new Circle(); // Allowed
    s->draw();
}