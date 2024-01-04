// Problem statement
// Given an integer ‘n’, return first n Fibonacci numbers using a generator function.

// Example:
// Input: ‘n’ = 5

// Output: 0 1 1 2 3

// Explanation: First 5 Fibonacci numbers are: 0, 1, 1, 2, and 3.
// Note:
// You don't need to print anything. Just implement the given function.
// Detailed explanation ( Input/output format, Notes, Images )
// Sample Input 1:
// 5
// Sample Output 1:
// 0 1 1 2 3
// Explanation Of Sample Input 1:
// The first 5 Fibonacci numbers are 0, 1, 1, 2, and 3.
// Sample Input 2:
// 3
// Sample Output 2:
// 0 1 1
// Explanation Of Sample Input 2:
// The first 5 Fibonacci numbers are 0, 1, 1.
// Expected time complexity
// The expected time complexity is O(n).
// Constraints:
// 1 <= n <= 45
// Time Limit: 1 s

// Coding Ninjas

vector<int> generateFibonacciNumbers(int n) {
    // Write your code here.
    if(n==1) return {0};
    if(n==2) return {0,1};
    vector<int> ans = {0,1};
    int prev = 0;
    int curr = 1;
    for(int i=2;i<n;i++){
        int temp = curr + prev;
        prev = curr;
        curr = temp;
        ans.push_back(temp);
    }
    return ans;
}