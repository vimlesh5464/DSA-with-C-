#include<iostream>
using namespace std;
//Remove Duplicate in String

void removeDup(string &s, string ans, int i, int map[26]){
  if(i==s.size()){
    cout<<"ans: "<< ans << " ";
    return;
  }
  char ch = s[i];
  int mapIdx = (int)(ch -'a');

  if(map[mapIdx]==true){
    removeDup(s, ans, i+1, map);
  }else{
    map[mapIdx] = true;
    removeDup(s, ans+s[i], i+1, map);
  }
}
int main(){
  string s = "aabb";
  string ans = " ";
  int map[26] = {false};
  removeDup(s, ans, 0,map);
  return 0;
}


// void removeDup(string &s, string ans, int map[26]){
//   if(s.size()==0){
//     cout<<"ans: "<< ans << " ";
//     return;
//   }
//   int n = s.size()
//   char ch = s[n-1]
//   int mapIdx = (int)(ch -'a');
//   s = s.substr(0, n-1);
//   if(map[mapIdx]==true){
//     removeDup(s, ans, map);
//   }else{
//     map[mapIdx] = true;
//     removeDup(s, ans+ch map);
//   }
// }