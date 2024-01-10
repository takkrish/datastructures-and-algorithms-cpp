// Problem statement
// You are given an integer array 'arr' of size 'N'.

// You must sort this array using 'Bubble Sort'.

// Note:
// Change in the input array itself. You don't need to return or print the elements.
// Example:
// Input: ‘N’ = 7
// 'arr' = [2, 13, 4, 1, 3, 6, 28]

// Output: [1 2 3 4 6 13 28]

// Explanation: After applying bubble sort on the input array, the output is [1 2 3 4 6 13 28].
// Detailed explanation ( Input/output format, Notes, Images )
// Sample Input 1:
// 7
// 2 13 4 1 3 6 28
// Sample Output 1:
// 1 2 3 4 6 13 28
// Explanation of Sample Output 1:
// After applying bubble sort on the input array, the output is [1 2 3 4 6 13 28].
// Sample Input 2:
// 5
// 9 3 6 2 0
// Sample Output 2:
// 0 2 3 6 9
// Explanation of Sample Output 2:
// After applying bubble sort on the input array, the output is [0 2 3 6 9].
// Constraints :
// 1 <= N <= 10^3
// 0 <= arr[i] <= 10^9
// Time Limit: 1 sec

// Coding Ninja

void bubbleSort(int arr[], int n) 
{
    //write your code here
    for(int i=0;i<n;i++){
        for(int j=0;j<n-1-i;j++){
            if(arr[j+1]<arr[j]) swap(arr[j],arr[j+1]);
        }
    }
}