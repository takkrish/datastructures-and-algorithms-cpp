// Problem statement
// A thief is robbing a store and can carry a maximal weight of W into his knapsack. There are N items and the ith item weighs wi and is of value vi. Considering the constraints of the maximum weight that a knapsack can carry, you have to find and return the maximum value that a thief can generate by stealing items.
// Detailed explanation ( Input/output format, Notes, Images )
// Constraints:
// 1 <= T <= 10
// 1 <= N <= 10^2
// 1<= wi <= 50
// 1 <= vi <= 10^2
// 1 <= W <= 10^3

// Time Limit: 1 second
// Sample Input:
// 1 
// 4
// 1 2 4 5
// 5 4 8 6
// 5
// Sample Output:
// 13

// Coding Ninjas

#include <bits/stdc++.h> 
int solve(vector<int> &wt, vector<int> &val, int idx, int cap,vector<vector<int>> &dp) {
	if(cap == 0 || idx < 0) return 0;
	if(dp[idx][cap] != -1) return dp[idx][cap];
	int nottake = solve(wt,val,idx-1,cap,dp);
	int take = 0;
	if(wt[idx] <= cap) take = val[idx] + solve(wt,val,idx-1,cap-wt[idx],dp);
	return dp[idx][cap] = max(take,nottake);
}
int knapsack(vector<int> wt, vector<int> val, int n, int cap) 
{
	vector<vector<int>> dp(n+1,vector<int>(cap+1,-1));
	return solve(wt,val,n-1,cap,dp);
}