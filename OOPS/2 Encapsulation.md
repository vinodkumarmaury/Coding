// ----Encapsulation--
//     It is wraping data(attribute or variable) and method(function) together in single unit(class).
//     It helps in organizing code by hiding the details of how an object works, exposing only the necessary functionalities. It also enhances security by preventing direct access to an object's internal state

// Here is the one-line difference before we dive deep:
// Encapsulation hides the Data (Variables) to protect it.
// Abstraction hides the Implementation (Complex Logic) to make it easy to use.

#include<bits/stdc++.h>
using namespace std;

class Student{
int roll;
string name;
int age;

public:
Student(int roll,string name,int age){
this->roll = roll;
this->name = name;
this->age = age;
cout<<"constructor is called"<<endl;
}
void display(){
    cout<<name<<endl;
}

~Student(){
    cout<<"Destructor is called"<<endl;
}

};

int main(){

Student s1(22,"vinod",22);
s1.display();
    return 0;
}


