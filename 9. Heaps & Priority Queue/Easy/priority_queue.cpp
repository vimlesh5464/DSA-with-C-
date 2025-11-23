#include<iostream>
#include<string>
#include<queue>
using namespace std;
class Student{
  public:
  string name;
  int mark;
  Student(string name,int mark){
    this->name=name;
    this->mark=mark;
  }
bool operator< (const Student&obj) const{
  return this->mark > obj.mark;
}

};
int main(){
  priority_queue<Student> pq;
  pq.push(Student("vimlesh",65));
  pq.push(Student("sachin",68));
  pq.push(Student("mithilesh",63));
  while(!pq.empty()){
    cout<<"top: "<<pq.top().name<<","<<pq.top().mark<<endl;
    pq.pop();
  }
  return 0;
}