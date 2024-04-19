// Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.

// An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

 

// Example 1:

// Input: grid = [
//   ["1","1","1","1","0"],
//   ["1","1","0","1","0"],
//   ["1","1","0","0","0"],
//   ["0","0","0","0","0"]
// ]
// Output: 1
// Example 2:

// Input: grid = [
//   ["1","1","0","0","0"],
//   ["1","1","0","0","0"],
//   ["0","0","1","0","0"],
//   ["0","0","0","1","1"]
// ]
// Output: 3
 

// Constraints:

// m == grid.length
// n == grid[i].length
// 1 <= m, n <= 300
// grid[i][j] is '0' or '1'.

// Leetcode

class Solution {
    int row[4] = {-1,0,1,0};
    int col[4] = {0,1,0,-1};
    void solve(int i,int j,vector<vector<char>>& grid,int m,int n) {
        grid[i][j] = '0';
        for(int k=0;k<4;k++){
            int ni = i + row[k];
            int nj = j + col[k];
            if(ni >=0 && ni < m && nj >= 0 && nj < n && grid[ni][nj] == '1') {
                solve(ni,nj,grid,m,n);
            }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int ans = 0;
        int m = grid.size();
        int n = grid[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == '1') {
                    ans++;
                    solve(i,j,grid,m,n);
                }
            }
        }
        return ans;
    }
};