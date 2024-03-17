// Given a string s, find any substring of length 2 which is also present in the reverse of s.

// Return true if such a substring exists, and false otherwise.

 

// Example 1:

// Input: s = "leetcode"

// Output: true

// Explanation: Substring "ee" is of length 2 which is also present in reverse(s) == "edocteel".

// Example 2:

// Input: s = "abcba"

// Output: true

// Explanation: All of the substrings of length 2 "ab", "bc", "cb", "ba" are also present in reverse(s) == "abcba".

// Example 3:

// Input: s = "abcd"

// Output: false

// Explanation: There is no substring of length 2 in s, which is also present in the reverse of s.

 

// Constraints:

// 1 <= s.length <= 100
// s consists only of lowercase English letters.

// Leetcode

class Solution {
public:
    bool isSubstringPresent(string s) {
        unordered_set<string> st;
        int n = s.length();
        for(int i=0;i<n-1;i++){
            st.insert(s.substr(i,2));
        }
        int start = 0;
        int end = n-1;
        while(start < end) {
            swap(s[start],s[end]);
            start++;
            end--;
        }
        for(int i=0;i<n-1;i++){
            string temp = s.substr(i,2);
            if(st.find(temp) != st.end()) return true;
        }
        return false;
    }
};