// Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.

// The overall run time complexity should be O(log (m+n)).

 

// Example 1:

// Input: nums1 = [1,3], nums2 = [2]
// Output: 2.00000
// Explanation: merged array = [1,2,3] and median is 2.
// Example 2:

// Input: nums1 = [1,2], nums2 = [3,4]
// Output: 2.50000
// Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.
 

// Constraints:

// nums1.length == m
// nums2.length == n
// 0 <= m <= 1000
// 0 <= n <= 1000
// 1 <= m + n <= 2000
// -106 <= nums1[i], nums2[i] <= 106

// Leetcode

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        int size = n1+n2;
        vector<int> v(size);
        int i1 = n1-1;
        int i2 = n2-1;
        int k = size-1;
        while(i1>=0 && i2>=0) {
            if(nums1[i1] > nums2[i2]) {
                v[k] = nums1[i1];
                i1--;
            }
            else {
                v[k] = nums2[i2];
                i2--;
            }
            k--;
        }
        while(i1>=0) {
            v[k] = nums1[i1];
            i1--;
            k--;
        }
        while(i2>=0) {
            v[k] = nums2[i2];
            i2--;
            k--;
        }
        if(size % 2 == 1) return v[size/2];
        return (v[size/2] + v[(size/2)-1])/2.0;
    }
};