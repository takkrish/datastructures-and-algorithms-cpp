// Given two strings s and t of lengths m and n respectively, return the minimum window 
// substring
// of s such that every character in t (including duplicates) is included in the window. If there is no such substring, return the empty string "".

// The testcases will be generated such that the answer is unique.

 

// Example 1:

// Input: s = "ADOBECODEBANC", t = "ABC"
// Output: "BANC"
// Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C' from string t.
// Example 2:

// Input: s = "a", t = "a"
// Output: "a"
// Explanation: The entire string s is the minimum window.
// Example 3:

// Input: s = "a", t = "aa"
// Output: ""
// Explanation: Both 'a's from t must be included in the window.
// Since the largest window of s only has one 'a', return empty string.
 

// Constraints:

// m == s.length
// n == t.length
// 1 <= m, n <= 105
// s and t consist of uppercase and lowercase English letters.
 

// Follow up: Could you find an algorithm that runs in O(m + n) time?

// Leetcode

class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> umap,mp;
        for(auto x : t) {
            umap[x]++;
        }
        int i=0;
        int st = 0;
        int end = 0;
        int len = 0;
        int n = s.length();
        int req = umap.size();
        int curr = 0;
        for(int j=0;j<n;j++){
            char ch = s[j];
            mp[ch]++;
            if(umap.count(ch) && mp[ch] == umap[ch]) {
                curr++;
            }
            while(i <= j && curr == req) {
                ch = s[i];
                if(len == 0 || j-i+1 < len) {
                    len = j-i+1;
                    st = i;
                }
                mp[ch]--;
                if(umap.count(ch) && mp[ch] < umap[ch]) curr--;
                i++;
            }
        }
        return len == 0 ? "" : s.substr(st,len);
    }
};