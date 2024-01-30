// Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

// Notice that the solution set must not contain duplicate triplets.

 

// Example 1:

// Input: nums = [-1,0,1,2,-1,-4]
// Output: [[-1,-1,2],[-1,0,1]]
// Explanation: 
// nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
// nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
// nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
// The distinct triplets are [-1,0,1] and [-1,-1,2].
// Notice that the order of the output and the order of the triplets does not matter.
// Example 2:

// Input: nums = [0,1,1]
// Output: []
// Explanation: The only possible triplet does not sum up to 0.
// Example 3:

// Input: nums = [0,0,0]
// Output: [[0,0,0]]
// Explanation: The only possible triplet sums up to 0.
 

// Constraints:

// 3 <= nums.length <= 3000
// -105 <= nums[i] <= 105

// Leetcode

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        int n = nums.size();
        int i = 0;
        while(i<n){
            int st = i+1;
            int end = n-1;
            int num = nums[i];
            while(st<end) {
                int sum = num + nums[st] + nums[end];
                if(sum == 0) {
                    ans.push_back({nums[i],nums[st],nums[end]});
                    int idx1 = st;
                    int idx2 = end;
                    while(st<end && nums[st] == nums[idx1]) st++;
                    while(st<end && nums[end] == nums[idx2]) end--;
                }
                else if (sum > 0) {
                    end--;
                }
                else {
                    st++;
                }
            }
            int idx = i;
            while(i < n && nums[idx] == nums[i]) i++;
        }
        return ans;
    }
};