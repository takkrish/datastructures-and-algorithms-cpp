// Problem statement
// You are given a sorted integer array 'arr' of size 'n'.

// You need to remove the duplicates from the array such that each element appears only once.

// Return the length of this new array.

// Note:
// Do not allocate extra space for another array. You need to do this by modifying the given input array in place with O(1) extra memory. 

// For example:
// 'n' = 5, 'arr' = [1 2 2 2 3].
// The new array will be [1 2 3].
// So our answer is 3.
// Detailed explanation ( Input/output format, Notes, Images )
// Sample input 1:
// 10
// 1 2 2 3 3 3 4 4 5 5 
// Sample output 1:
// 5
// Explanation of sample input 1:
// The new array will be [1 2 3 4 5].
// So our answer is 5.
// Sample input 2:
// 9
// 1 1 2 3 3 4 5 5 5 
// Sample output 2:
// 5
// Expected time complexity:
// The expected time complexity is O(n).
// Constraints :
// 1 <= 'n' <= 10^6
// -10^9 <= 'arr[i]' <=10^9

// Where ‘arr[i]’ is the value of elements of the array.

// Time limit: 1 sec

// Coding Ninjas

int removeDuplicates(vector<int> &arr, int n) {
	// Write your code here.
	int count = 0;
	for(int i=1;i<n;i++){
		if(arr[i]!=arr[i-1]) count++;
	}
	return count+1;
}

// Given an integer array nums sorted in non-decreasing order, remove the duplicates in-place such that each unique element appears only once. The relative order of the elements should be kept the same. Then return the number of unique elements in nums.

// Consider the number of unique elements of nums to be k, to get accepted, you need to do the following things:

// Change the array nums such that the first k elements of nums contain the unique elements in the order they were present in nums initially. The remaining elements of nums are not important as well as the size of nums.
// Return k.
// Custom Judge:

// The judge will test your solution with the following code:

// int[] nums = [...]; // Input array
// int[] expectedNums = [...]; // The expected answer with correct length

// int k = removeDuplicates(nums); // Calls your implementation

// assert k == expectedNums.length;
// for (int i = 0; i < k; i++) {
//     assert nums[i] == expectedNums[i];
// }
// If all assertions pass, then your solution will be accepted.

 

// Example 1:

// Input: nums = [1,1,2]
// Output: 2, nums = [1,2,_]
// Explanation: Your function should return k = 2, with the first two elements of nums being 1 and 2 respectively.
// It does not matter what you leave beyond the returned k (hence they are underscores).
// Example 2:

// Input: nums = [0,0,1,1,1,2,2,3,3,4]
// Output: 5, nums = [0,1,2,3,4,_,_,_,_,_]
// Explanation: Your function should return k = 5, with the first five elements of nums being 0, 1, 2, 3, and 4 respectively.
// It does not matter what you leave beyond the returned k (hence they are underscores).
 

// Constraints:

// 1 <= nums.length <= 3 * 104
// -100 <= nums[i] <= 100
// nums is sorted in non-decreasing order.

// Leetcode

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int count = 1;
        int j=1;
        int n = nums.size();
        for(int i=1;i<n;i++){
            if(nums[i]!=nums[i-1]){
                nums[j] = nums[i];
                j++;
                count++;
            }
        }
        return count;
    }
};