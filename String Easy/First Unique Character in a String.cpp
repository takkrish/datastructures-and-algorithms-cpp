// Given a string s, find the first non-repeating character in it and return its index. If it does not exist, return -1.

 

// Example 1:

// Input: s = "leetcode"
// Output: 0
// Example 2:

// Input: s = "loveleetcode"
// Output: 2
// Example 3:

// Input: s = "aabb"
// Output: -1
 

// Constraints:

// 1 <= s.length <= 105
// s consists of only lowercase English letters.

// Leetcode

class Solution {
public:
    int firstUniqChar(string s) {
        map<char,int> mp;
        for(auto &x : s) mp[x]++;
        int n = s.length();
        for(int i=0;i<n;i++) if(mp[s[i]] == 1) return i;
        return -1;
    }
};