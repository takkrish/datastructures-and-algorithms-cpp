// Given a set of distinct positive integers nums, return the largest subset answer such that every pair (answer[i], answer[j]) of elements in this subset satisfies:

// answer[i] % answer[j] == 0, or
// answer[j] % answer[i] == 0
// If there are multiple solutions, return any of them.

 

// Example 1:

// Input: nums = [1,2,3]
// Output: [1,2]
// Explanation: [1,3] is also accepted.
// Example 2:

// Input: nums = [1,2,4,8]
// Output: [1,2,4,8]
 

// Constraints:

// 1 <= nums.length <= 1000
// 1 <= nums[i] <= 2 * 109
// All the integers in nums are unique.

// Leetcode

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        vector<int> ans;
        vector<int> count(n,1);
        vector<int> prev(n,-1);
        int maxind = 0;
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i]%nums[j] == 0) {
                    if(count[i] < count[j] + 1) {
                        count[i] = count[j]+1;
                        prev[i] = j;
                    }
                }
            }
            if(count[maxind] < count[i]) {
                maxind = i;
            }
        }
        while(maxind>=0) {
            ans.push_back(nums[maxind]);
            maxind = prev[maxind];
        }
        return ans;
    }
};