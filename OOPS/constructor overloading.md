#include <iostream>
using namespace std;

class Student {
public:
    string name;

    // Constructor 1: No arguments
    Student() {
        name = "Unknown";
    }

    // Constructor 2: With argument
    Student(string n) {
        name = n;
    }
};

int main() {
    Student s1;             // Calls Constructor 1
    Student s2("Vinod");    // Calls Constructor 2
    
    cout << s1.name << endl; // Output: Unknown
    cout << s2.name << endl; // Output: Vinod
    return 0;
}