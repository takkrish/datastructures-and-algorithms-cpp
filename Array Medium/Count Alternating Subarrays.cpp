// You are given a 
// binary array
//  nums.

// We call a 
// subarray
//  alternating if no two adjacent elements in the subarray have the same value.

// Return the number of alternating subarrays in nums.

 

// Example 1:

// Input: nums = [0,1,1,1]

// Output: 5

// Explanation:

// The following subarrays are alternating: [0], [1], [1], [1], and [0,1].

// Example 2:

// Input: nums = [1,0,1,0]

// Output: 10

// Explanation:

// Every subarray of the array is alternating. There are 10 possible subarrays that we can choose.

 

// Constraints:

// 1 <= nums.length <= 105
// nums[i] is either 0 or 1.

// Leetcode

class Solution {
public:
    long long countAlternatingSubarrays(vector<int>& nums) {
        int st = 0;
        int end = 0;
        int n = nums.size();
        int prev = -1;
        long long ans = 0;
        while(end < n) {
            if(nums[end] != prev) {
                prev = nums[end];
                ans += end-st+1;
                end++;
            }
            else {
                prev = -1;
                st = end;
            }
        }
        return ans;
    }
};