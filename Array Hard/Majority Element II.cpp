// Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.

 

// Example 1:

// Input: nums = [3,2,3]
// Output: [3]
// Example 2:

// Input: nums = [1]
// Output: [1]
// Example 3:

// Input: nums = [1,2]
// Output: [1,2]
 

// Constraints:

// 1 <= nums.length <= 5 * 104
// -109 <= nums[i] <= 109
 

// Follow up: Could you solve the problem in linear time and in O(1) space?

// Leetcode

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int elem1 = INT_MIN,elem2 = INT_MIN;
        int freq1 = 0,freq2 = 0;
        for(auto x : nums) {
            if(freq1 == 0 && x != elem2) {
                elem1 = x;
                freq1++;
            }
            else if(freq2 == 0 && x != elem1) {
                elem2 = x;
                freq2++;
            }
            else if(x == elem1) {
                freq1++;
            }
            else if(x == elem2) {
                freq2++;
            }
            else {
                freq1--;
                freq2--;
            }
        }
        freq1 = freq2 = 0;
        for(auto x : nums) {
            if(x == elem1) freq1++;
            else if(x == elem2) freq2++;
        }
        vector<int> ans;
        int lim = n/3;
        if(freq1 > lim) ans.push_back(elem1);
        if(freq2 > lim) ans.push_back(elem2);
        return ans;
    }
};