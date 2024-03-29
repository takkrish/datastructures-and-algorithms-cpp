// You are given an integer array nums and a positive integer k.

// Return the number of subarrays where the maximum element of nums appears at least k times in that subarray.

// A subarray is a contiguous sequence of elements within an array.

 

// Example 1:

// Input: nums = [1,3,2,3,3], k = 2
// Output: 6
// Explanation: The subarrays that contain the element 3 at least 2 times are: [1,3,2,3], [1,3,2,3,3], [3,2,3], [3,2,3,3], [2,3,3] and [3,3].
// Example 2:

// Input: nums = [1,4,2,1], k = 3
// Output: 0
// Explanation: No subarray contains the element 4 at least 3 times.
 

// Constraints:

// 1 <= nums.length <= 105
// 1 <= nums[i] <= 106
// 1 <= k <= 105

// Leetcode

class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int maxi = 0;
        for(auto &x : nums) {
            maxi = max(maxi,x);
            mp[x]++;
        }
        if(mp[maxi] < k) return 0;
        int st = 0;
        int end = 0;
        int n = nums.size();
        int count = 0;
        long long ans = 0;
        while(end < n) {
            while(end < n && count < k) {
                if(nums[end] == maxi) count++;
                end++;
            }
            while(count == k) {
                ans += (n-end+1);
                if(nums[st] == maxi) count--;
                st++;
            }
        }
        return ans;
    }
};