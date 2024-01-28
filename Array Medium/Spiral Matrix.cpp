// Given an m x n matrix, return all elements of the matrix in spiral order.

 

// Example 1:


// Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
// Output: [1,2,3,6,9,8,7,4,5]
// Example 2:


// Input: matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
// Output: [1,2,3,4,8,12,11,10,9,5,6,7]
 

// Constraints:

// m == matrix.length
// n == matrix[i].length
// 1 <= m, n <= 10
// -100 <= matrix[i][j] <= 100

// Leetcode

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> ans;
        int ub,lb,rb,bb;
        ub = lb = 0;
        rb = n-1;
        bb = m-1;
        while(ub <= bb && lb <= rb) {
            for(int i=lb;i<=rb;i++){
                ans.push_back(matrix[ub][i]);
            }
            ub++;
            for(int i=ub;i<=bb;i++){
                ans.push_back(matrix[i][rb]);
            }
            rb--;
            if(ub<=bb){
                for(int i=rb;i>=lb;i--){
                    ans.push_back(matrix[bb][i]);
                }
                bb--;
            }
            if(lb<=rb){
                for(int i=bb;i>=ub;i--){
                    ans.push_back(matrix[i][lb]);
                }
                lb++;
            }
        }
        return ans;
    }
};