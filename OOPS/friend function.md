// A function that is not a member of the class but has permission to access its private members. Note: This breaks encapsulation, so use it sparingly.

#include <iostream>
using namespace std;


class Box{
  int num;
  public:
  Box(int num){
    this->num = num;
  }
  friend void print(Box num);
};

 void print(Box b){
      cout<<b.num<<endl;
    }

int main() 
{
  Box obj(5);
  print(obj);
    return 0;
}