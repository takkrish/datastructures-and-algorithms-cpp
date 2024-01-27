// Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.

// You must write an algorithm that runs in O(n) time.

 

// Example 1:

// Input: nums = [100,4,200,1,3,2]
// Output: 4
// Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.
// Example 2:

// Input: nums = [0,3,7,2,5,8,4,6,0,1]
// Output: 9
 

// Constraints:

// 0 <= nums.length <= 105
// -109 <= nums[i] <= 109

// Leetcode

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> uset;
        for(auto x : nums) uset.insert(x);
        int ans = 0;
        for(auto x : nums) {
            if(uset.find(x-1) == uset.end()) {
                int count = 0;
                int num = x;
                while(uset.find(num) != uset.end()){
                    count++;
                    num++;
                }
                ans = max(ans,count);
            } 
        }
        return ans;
    }
};