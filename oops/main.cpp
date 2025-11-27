#include<iostream>
using namespace std;
class OOPS{
  string name;
  int age;
public:
OOPS() {                    // Default constructor
  name = "";
  age = 0;
}

OOPS(string name,int age){
  this->name=name;
  this->age=age;
}
void getvalue(string name){
  cout<< "vimlesh";
}
void setvalue(string name){
  name = name;
  
}
void show(string name, int age){
  cout<<"name :"<<name<<" " << endl;
  cout<< "Age :"<<age<<" " << endl;
}

};
int main(){
  OOPS p;
  p.show("vimlesh",21);
  p.show("sachin",21);
  p.getvalue("vimlesh");
  return 0;
}