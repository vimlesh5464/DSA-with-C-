#include<iostream>
#include<vector>
using namespace std;
class MaxHeap{
  vector<int> heap;
  void heapifyDown(int i) {
    int n = heap.size();
    int largest = i;

    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && heap[left] > heap[largest])
        largest = left;

    if (right < n && heap[right] > heap[largest])
        largest = right;

    if (largest != i) {
        swap(heap[i], heap[largest]);
        heapifyDown(largest);
    }
}
  public:
  void push(int val){
    heap.push_back(val);
    int x = heap.size()-1;
    int par = (x-1)/2;
    while(par>=0 && heap[x]>heap[par]){
      swap(heap[x],heap[par]);
      x = par;
      par = (x-1)/2;
    }
  }
  void pop(){
    if (heap.size() == 0) return;

        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(0);
  }
 int top(){
  if (heap.size() == 0) {
    cout << "Heap is empty!\n";
    return -1;
}
  return heap[0];
 }
 bool empty(){
  return heap.size()==0;
 }
 int size() {
  return heap.size();
}
};
int main(){
  MaxHeap h;

    h.push(10);
    h.push(40);
    h.push(20);
    h.push(30);

    cout << "Top: " << h.top() << endl;  // 40

    h.pop();
    cout << "Top after pop: " << h.top() << endl; // 30

    h.push(50);
    cout << "Top after pushing 50: " << h.top() << endl; // 50

    return 0;
}