#include <iostream>
using namespace std;

class Printer {
public:
    // Form 1: Takes an integer
    void print(int i) {
        cout << "Printing Integer: " << i << endl;
    }

    // Form 2: Takes a double (Same name, different type)
    void print(double f) {
        cout << "Printing Float: " << f << endl;
    }

    // Form 3: Takes a string (Same name, different type)
    void print(string s) {
        cout << "Printing String: " << s << endl;
    }
};

int main() {
    Printer p;
    p.print(10);      // Compiler selects Form 1
    p.print(10.5);    // Compiler selects Form 2
    p.print("Hello"); // Compiler selects Form 3
    return 0;
}