#include <iostream>
using namespace std;

class Vector {
    int* arr;
    int size;

public:
    // 1. Parameterized Constructor
    Vector(int s) {
        size = s;
        arr = new int[size]; // Dynamic Allocation on Heap
        for(int i=0; i<size; i++) arr[i] = 0;
        cout << "Constructor called" << endl;
    }

    // 2. Custom Copy Constructor (DEEP COPY)
    Vector(const Vector &source) {
        size = source.size;
        // Allocate NEW memory instead of pointing to source's memory
        arr = new int[size]; 
        for(int i=0; i<size; i++) {
            arr[i] = source.arr[i]; // Copy values manually
        }
        cout << "Deep Copy Constructor called" << endl;
    }

    // 3. Destructor
    ~Vector() {
        delete[] arr; // Prevent Memory Leak
        cout << "Memory freed" << endl;
    }
};

int main() {
    Vector v1(5); 
    Vector v2 = v1; // Calls Deep Copy Constructor
    // If we didn't write the copy constructor, v2.arr would point to v1.arr.
    // When main ends, v1 is destroyed (memory freed). 
    // Then v2 is destroyed, trying to free the SAME memory -> Crash!
}