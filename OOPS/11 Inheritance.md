// Concept: The capability of a class to derive properties and characteristics from another class.

// Parent/Base Class: The class whose properties are inherited.

// Child/Derived Class: The class that inherits.

// Modes of Inheritance: Public, Private, and Protected modes determine how the parent's properties appear in the child class. Note that private members of a parent are never directly accessible in the child class.

// Types of Inheritance:

// Single: One parent, one child.

// Multi-level: Parent -> Child -> Grandchild.

// Multiple: One child inherits from two or more parents (e.g., A "Teaching Assistant" is both a "Teacher" and a "Student").

// Hierarchical: Multiple children inherit from one parent.

#include <iostream>
using namespace std;

class Person { // Grandparent
public:
    Person() { cout << "Person Created" << endl; }
};

// VIRTUAL PUBLIC is the fix
class Student : virtual public Person { 
public:
    Student() { cout << "Student Created" << endl; }
};

// VIRTUAL PUBLIC is the fix
class Teacher : virtual public Person { 
public:
    Teacher() { cout << "Teacher Created" << endl; }
};

class TA : public Student, public Teacher { // Inherits from both
public:
    TA() { cout << "TA Created" << endl; }
};

int main() {
    TA ta1;
    // Output Order:
    // 1. Person Created (Only ONCE because of virtual)
    // 2. Student Created
    // 3. Teacher Created
    // 4. TA Created
    return 0;
}