// Problem statement
// You are given an array of ‘N’ integers where each integer value is between ‘1’ and ‘N’.

// Each integer appears exactly once except for ‘P’, which appears exactly twice, and ‘Q’, which is missing.

// Your task is to find ‘P’ and ‘Q’ and return them respectively.

// Example:
// Input: ‘N’ = 4
// ‘A’ = [1, 2, 3, 2]

// Output: {2, 4}

// Explanation: The integer appearing twice is ‘2’, and the integer missing is ‘4’.
// Detailed explanation ( Input/output format, Notes, Images )
// Sample Input 1:
// 4
// 1 2 3 2
// Sample Output 1:
// 2 4
// Explanation Of Sample Input 1:
// Input: ‘N’ = 5
// ‘A’ = [1, 2, 3, 2]

// Output: {2, 4}

// Explanation: The integer appearing twice is ‘2’, and the integer missing is ‘4’.
// Sample Input 2:
// 3
// 1 2 1
// Sample Output 2:
// 1 3
// Constraints:
// 2 <= N <= 10^5
// 1 <= A[i] <= N

// Time Limit: 1-sec

// Coding Ninjas

vector<int> findMissingRepeatingNumbers(vector < int > a) {
    // Write your code here
        int _xor = 0;
    int n = a.size();
    for(int i=0;i<n;i++){
        _xor ^= a[i];
        _xor ^= (i+1);
    }
    int shift = 0;
    while((_xor & (1<<shift)) == 0) shift++;
    int num = (1 << shift);
    int one = 0;
    int zero = 0;
    for(int i=0;i<n;i++){
        if((a[i] & num) == 0) zero ^= a[i];
        else one ^= a[i];
    }
    for(int i=1;i<=n;i++){
        if((i & num) == 0) zero ^= i;
        else one ^= i;
    }
    int count = 0;
    for(auto x : a) {
        if(x == zero) count++;
    }
    if(count == 2) return {zero,one};
    return {one,zero};
}