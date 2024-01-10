// Problem statement
// You are given the starting 'l' and the ending 'r' positions of the array 'ARR'.

// You must sort the elements between 'l' and 'r'.

// Note:
// Change in the input array itself. So no need to return or print anything.
// Example:
// Input: ‘N’ = 7,
// 'ARR' = [2, 13, 4, 1, 3, 6, 28]

// Output: [1 2 3 4 6 13 28]

// Explanation: After applying 'merge sort' on the input array, the output is [1 2 3 4 6 13 28].
// Detailed explanation ( Input/output format, Notes, Images )
// Sample Input 1:
// 7
// 2 13 4 1 3 6 28
// Sample Output 1:
// 1 2 3 4 6 13 28
// Explanation of Sample Output 1:
// After applying 'merge sort' on the input array, the output is [1 2 3 4 6 13 28].
// Sample Input 2:
// 5
// 9 3 6 2 0
// Sample Output 2:
// 0 2 3 6 9
// Explanation of Sample Output 2:
// After applying 'merge sort' on the input array, the output is [0 2 3 6 9].
// Constraints :
// 1 <= N <= 10^3
// 0 <= ARR[i] <= 10^9

// Coding Ninjas

#include<bits/stdc++.h>
using namespace std;

void merge(int arr[],int low, int mid,int high) {
    vector<int> temp;
    int left = low;
    int right = mid + 1;
    while (left <= mid && right <= high) {
        if (arr[left] <= arr[right]) {
            temp.push_back(arr[left]);
            left++;
        }
        else {
            temp.push_back(arr[right]);
            right++;
        }
    }
    while (left <= mid) {
        temp.push_back(arr[left]);
        left++;
    }
    while (right <= high) {
        temp.push_back(arr[right]);
        right++;
    }
    for (int i = low; i <= high; i++) {
        arr[i] = temp[i-low];
    }

}

void mergeSort(int arr[], int l, int r) {
    if(l >= r) return;
    int mid = l + (r-l)/2;
    mergeSort(arr,l,mid);
    mergeSort(arr,mid+1,r);
    merge(arr,l,mid,r);
}