#include <iostream>
using namespace std;

class Person{
  string gender;
  protected:
  string address;
  public:
  string name;
  int age;
  Person(string name,int age,string gender, string address){
    this->name = name;
    this->age = age;
    this->gender = gender;
    this->address = address;
    cout<<"Person constructor is called"<<endl;
  }
  
  void display(){
    cout<<name<<" "<<age<<" "<<gender<<endl;
  }
  
  ~Person(){
        cout<<"Person destructor is called"<<endl;
  }
};

class Student:public Person{
  public:
  string Degree;
  Student(string name,int age,string gender, string address,string Degree):Person(name,age,gender,address){
    this->Degree = Degree;
    cout<<"Student constructor is called"<<endl;
  }
  
  void display(){
    cout<<name<<" "<<age<<" "<<Degree<<"  "<<address<<endl;
  }
  
  ~Student(){
   cout<<"Student destructor is called"<<endl;
  }
};

int main() 
{
    Person p("vinod",22,"male","lucknow");
    p.display();
    Student s("vinod",22,"male","lucknow","B.Tech.");
    s.display();
    return 0;
}