#include <iostream>
#include<vector>
#include <queue> 
#include <utility> 
using namespace std;

class Solution {
public:
    void dfs(vector<vector<int>>& image, int r, int c, int color, int startColor) {
        int rows = image.size();
        int cols = image[0].size();
        
        // Boundary + already visited + different color check
        if (r < 0 || c < 0 || r >= rows || c >= cols || image[r][c] != startColor) 
            return;
        
        // Fill with new color
        image[r][c] = color;
        
        // 4 directions
        dfs(image, r+1, c, color, startColor);
        dfs(image, r-1, c, color, startColor);
        dfs(image, r, c+1, color, startColor);
        dfs(image, r, c-1, color, startColor);
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int startColor = image[sr][sc];
        
        // If same color, nothing to change
        if (startColor == color) return image;
        
        dfs(image, sr, sc, color, startColor);
        return image;
    }
};

// Example usage
int main() {
    Solution sol;
    vector<vector<int>> image = {
        {1,1,1},
        {1,1,0},
        {1,0,1}
    };
    int sr = 1, sc = 1, newColor = 2;

    vector<vector<int>> result = sol.floodFill(image, sr, sc, newColor);

    cout << "Flood Filled Image:" << endl;
    for (auto& row : result) {
        for (auto& pixel : row) {
            cout << pixel << " ";
        }
        cout << endl;
    }

    return 0;
}
