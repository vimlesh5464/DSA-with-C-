# 1079. Letter Tile Possibilities.py - Python skeleton converted from C++

# Original C++ code:
# // You have n  tiles, where each tile has one letter tiles[i] printed on it.
# 
# // Return the number of possible non-empty sequences of letters you can 
# //make using the letters printed on those tiles.
# 
#  
# 
# // Example 1:
# 
# // Input: tiles = "AAB"
# // Output: 8
# // Explanation: The possible sequences are "A", "B", "AA", "AB", "BA", "AAB", "ABA", "BAA".
# 
# // Example 2:
# 
# // Input: tiles = "AAABBC"
# // Output: 188
# 
# // Example 3:
# 
# // Input: tiles = "V"
# // Output: 1
# 
#  
# 
# // Constraints:
# 
# //     1 <= tiles.length <= 7
# //     tiles consists of uppercase English letters.
# 
#  
# 
# #include<iostream>
# #include<vector>
# #include<string>
# using namespace std;
# 
# class Solution {
#   public:
#       int dfs(vector<int>& freq) {
#           int count = 0;
#   
#           for (int i = 0; i < 26; i++) {
#               if (freq[i] == 0) continue;
#   
#               // choose this tile
#               count++;
#               freq[i]--;
#   
#               // explore more sequences
#               count += dfs(freq);
#   
#               // backtrack
#               freq[i]++;
#           }
#           return count;
#       }
#   
#       int numTilePossibilities(string tiles) {
#           vector<int> freq(26, 0);
#   
#           for (char c : tiles) {
#               freq[c - 'A']++;
#           }
#   
#           return dfs(freq);
#       }
#   };
#   

def main():
    pass  # TODO: Convert C++ code to Python here

if __name__ == '__main__':
    main()
