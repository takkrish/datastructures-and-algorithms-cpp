// Given an integer array arr, partition the array into (contiguous) subarrays of length at most k. After partitioning, each subarray has their values changed to become the maximum value of that subarray.

// Return the largest sum of the given array after partitioning. Test cases are generated so that the answer fits in a 32-bit integer.

 

// Example 1:

// Input: arr = [1,15,7,9,2,5,10], k = 3
// Output: 84
// Explanation: arr becomes [15,15,15,9,10,10,10]
// Example 2:

// Input: arr = [1,4,1,5,7,3,6,1,9,9,3], k = 4
// Output: 83
// Example 3:

// Input: arr = [1], k = 1
// Output: 1
 

// Constraints:

// 1 <= arr.length <= 500
// 0 <= arr[i] <= 109
// 1 <= k <= arr.length

// Leetcode

class Solution {
    int solve(vector<int>& arr, int k,int idx,vector<int> &dp){
        if(idx < 0) return 0;
        if(dp[idx] != -1) return dp[idx];
        int maxi = 0;
        int best = 0;
        for(int i=1;i<=k && (idx-i >= 0);i++){
            maxi = max(maxi,arr[idx-i]);
            best = max(best ,(maxi * i) + solve(arr,k,idx-i,dp));
        }
        return dp[idx] = best;
    }
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n+1,-1);
        return solve(arr,k,n,dp);
    }
};