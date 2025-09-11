
#include <iostream>
#include <stdlib.h>

using namespace std;

// [Naive Approach] Dividing the space into two halves

//   The idea to implement two stacks is to divide the array into two halves and assign 
//   two halves to two stacks, i.e., use arr[0] to arr[n/2] for stack1,
//    and arr[(n/2) + 1] to arr[n-1] for stack2 where arr[] is the array to
//     be used to implement two stacks and size of array be n. 

// Time Complexity: 

//     Both Push operation: O(1)
//     Both Pop operation: O(1)

// Auxiliary Space: O(n), Use of array to implement stack.
class twoStacks {
    int* arr;
    int size;
    int top1, top2;

public:
    twoStacks(int n) 
    { 
        size = n;
        arr = new int[n]; 
        top1 = n / 2 + 1;  // top1 starts from the middle of the array + 1
        top2 = n / 2;      // top2 starts from the middle of the array
    }

    void push1(int x)
    {
        if (top1 < size) {  // Ensure there is space for stack1
            arr[top1++] = x;  // Increment top1 and then insert the element
        }
        else {
            cout << "Stack Overflow for stack1" << endl;
        }
    }

    void push2(int x)
    {
        if (top2 >= 0) {  // Ensure there is space for stack2
            arr[top2--] = x;  // Decrement top2 and then insert the element
        }
        else {
            cout << "Stack Overflow for stack2" << endl;
        }
    }

    int pop1()
    {
        if (top1 > size / 2) {  // Ensure stack1 is not empty
            return arr[--top1];  // Decrement top1 and return the element
        }
        else {
            return -1;  // Stack Underflow for stack1
        }
    }

    int pop2()
    {
        if (top2 < size / 2) {  // Ensure stack2 is not empty
            return arr[++top2];  // Increment top2 and return the element
        }
        else {
            return -1;  // Stack Underflow for stack2
        }
    }
};


// [Expected Approach] Starting from endpoints

//     The idea is to start two stacks from two extreme corners of arr[]. 
// Time Complexity: 

//     Both Push operation: O(1)
//     Both Pop operation: O(1)

// Auxiliary Space: O(n), Use of the array to implement stack.

class twoStacks {
  int *arr;
  int size;
  int top1, top2;

public:
  twoStacks(int n) {
      size = n;
      arr = new int[n];
      top1 = -1;
      top2 = size;
  }

  void push1(int x) {
      if (top1 < top2 - 1) {
          top1++;
          arr[top1] = x;
      }
  }

  void push2(int x) {
      if (top1 < top2 - 1) {
          top2--;
          arr[top2] = x;
      }
  }

  int pop1() {
      if (top1 >= 0) {
          int x = arr[top1];
          top1--;
          return x;
      } else
          return -1;
  }

  int pop2() {
      if (top2 < size) {
          int x = arr[top2];
          top2++;
          return x;
      } else
          return -1;
  }
};

int main()
{
    twoStacks ts(5);  
    ts.push1(2);
    ts.push1(3);
    ts.push2(4);
    cout << ts.pop1() << " ";  
    cout << ts.pop2() << " ";  
    cout << ts.pop2() << " ";  
    return 0;
}