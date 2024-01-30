// Given an array nums of n integers, return an array of all the unique quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:

// 0 <= a, b, c, d < n
// a, b, c, and d are distinct.
// nums[a] + nums[b] + nums[c] + nums[d] == target
// You may return the answer in any order.

 

// Example 1:

// Input: nums = [1,0,-1,0,-2,2], target = 0
// Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]
// Example 2:

// Input: nums = [2,2,2,2,2], target = 8
// Output: [[2,2,2,2]]
 

// Constraints:

// 1 <= nums.length <= 200
// -109 <= nums[i] <= 109
// -109 <= target <= 109

// Leetcode

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        int n = nums.size();
        for(int i=0;i<n-3;){
            for(int j=i+1;j<n-2;){
                long long sum = nums[i] + nums[j];
                long long rem = target - sum;
                int st = j+1;
                int end = n-1;
                while(st<end) {
                    long long temp = nums[st] + nums[end];
                    if(temp == rem) {
                        ans.push_back({nums[i],nums[j],nums[st],nums[end]});
                        int idx1 = st;
                        int idx2 = end;
                        while(st < end && nums[st] == nums[idx1]) st++;
                        while(st < end && nums[end] == nums[idx2]) end--;
                    }
                    else if(temp < rem) {
                        st++;
                    }
                    else end--;
                }
                int idx = j;
                while(j<n-2 && nums[j]==nums[idx]) j++;
            }
            int idx = i;
            while(i<n-3 && nums[i]==nums[idx]) i++;
        }
        return ans;
    }
};