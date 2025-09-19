#include<iostream>
#include<vector>
#include<stack>
using namespace std;

class StockSpanner {
public:
    stack<pair<int, int>> s; // {price, span}
    
    StockSpanner() {
        // nothing to initialize explicitly
    }
    
    int next(int price) {
        int span = 1;
        
        // While stack top has price <= current price
        while (!s.empty() && s.top().first <= price) {
            span += s.top().second; // add its span
            s.pop();
        }
        
        // Push current price with its span
        s.push({price, span});
        
        return span;
    }
};

// Example usage
int main() {
    StockSpanner* obj = new StockSpanner();
    vector<int> prices = {100, 80, 60, 70, 60, 75, 85};
    for (int p : prices) {
        cout << obj->next(p) << " ";
    }
    cout << endl;
    return 0;
}
