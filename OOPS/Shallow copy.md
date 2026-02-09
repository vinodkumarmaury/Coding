#include<bits/stdc++.h>
using namespace std;

class Student{
public:
string name;
int  age;
int *arr;
Student(string name,int age){
this->name = name;
this->age = age;
arr = new int[age];
for(int i = 0;i<age;i++){
arr[i] = i;
}
cout<<"constructor is called"<<endl;
}

Student(const Student &s){
    this->name = s.name;
    this->age = s.age;
    arr = new int[age];
    for(int i = 0;i<age;i++){
        arr[i] = i;
    }
}
void display(){
    cout<<name<<" "<<age<<endl;
    for(int i = 0;i<age;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}


~Student(){
    cout<<"memory freed"<<endl;

}

};


int main(){

Student s1("vinod",22);
s1.display();
Student s2 = s1;
s2.age = 5;
s1.display();
s2.display();

    return 0;
}

