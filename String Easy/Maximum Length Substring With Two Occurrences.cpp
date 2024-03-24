// Given a string s, return the maximum length of a 
// substring
//  such that it contains at most two occurrences of each character.
 

// Example 1:

// Input: s = "bcbbbcba"

// Output: 4

// Explanation:

// The following substring has a length of 4 and contains at most two occurrences of each character: "bcbbbcba".
// Example 2:

// Input: s = "aaaa"

// Output: 2

// Explanation:

// The following substring has a length of 2 and contains at most two occurrences of each character: "aaaa".
 

// Constraints:

// 2 <= s.length <= 100
// s consists only of lowercase English letters.

// Leetcode

class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n = s.length();
        int st = 0;
        int end = 0;
        int ans = 0;
        unordered_map<char,int> mp;
        while(st <= end && end < n) {
            mp[s[end]]++;
            while(st<=end && mp[s[end]] > 2) {
                mp[s[st]]--;
                st++;
            }
            end++;
            ans = max(ans,end-st);
        }
        return ans;
    }
};