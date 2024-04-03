// Given an m x n grid of characters board and a string word, return true if word exists in the grid.

// The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once.

 

// Example 1:


// Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
// Output: true
// Example 2:


// Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "SEE"
// Output: true
// Example 3:


// Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCB"
// Output: false
 

// Constraints:

// m == board.length
// n = board[i].length
// 1 <= m, n <= 6
// 1 <= word.length <= 15
// board and word consists of only lowercase and uppercase English letters.
 

// Follow up: Could you use search pruning to make your solution faster with a larger board?

// Leetcode

class Solution {
    bool solve(int i,int j,int idx,int m,int n,vector<vector<char>>& board, string &word,int k,vector<vector<bool>> &vis) {
        if(idx == k) return true;
        if(i<0 || i>=m || j<0 || j>=n) return false;
        if(vis[i][j]) return false;
        if(word[idx] != board[i][j]) return false;
        vis[i][j] = 1;
        int row[] = {-1,0,1,0};
        int col[] = {0,1,0,-1};
        if(solve(i+row[0],j+col[0],idx+1,m,n,board,word,k,vis)) return true;
        if(solve(i+row[1],j+col[1],idx+1,m,n,board,word,k,vis)) return true;
        if(solve(i+row[2],j+col[2],idx+1,m,n,board,word,k,vis)) return true;
        if(solve(i+row[3],j+col[3],idx+1,m,n,board,word,k,vis)) return true;
        vis[i][j] = 0;
        return false;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        int k = word.length();
        vector<vector<bool>> vis(m,vector<bool>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(solve(i,j,0,m,n,board,word,k,vis)) return true;
            }
        }
        return false;
    }
};