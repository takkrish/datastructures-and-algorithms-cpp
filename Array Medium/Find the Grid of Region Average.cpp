// You are given a 0-indexed m x n grid image which represents a grayscale image, where image[i][j] represents a pixel with intensity in the range[0..255]. You are also given a non-negative integer threshold.

// Two pixels image[a][b] and image[c][d] are said to be adjacent if |a - c| + |b - d| == 1.

// A region is a 3 x 3 subgrid where the absolute difference in intensity between any two adjacent pixels is less than or equal to threshold.

// All pixels in a region belong to that region, note that a pixel can belong to multiple regions.

// You need to calculate a 0-indexed m x n grid result, where result[i][j] is the average intensity of the region to which image[i][j] belongs, rounded down to the nearest integer. If image[i][j] belongs to multiple regions, result[i][j] is the average of the rounded down average intensities of these regions, rounded down to the nearest integer. If image[i][j] does not belong to any region, result[i][j] is equal to image[i][j].

// Return the grid result.

 

// Example 1:


// Input: image = [[5,6,7,10],[8,9,10,10],[11,12,13,10]], threshold = 3
// Output: [[9,9,9,9],[9,9,9,9],[9,9,9,9]]
// Explanation: There exist two regions in the image, which are shown as the shaded areas in the picture. The average intensity of the first region is 9, while the average intensity of the second region is 9.67 which is rounded down to 9. The average intensity of both of the regions is (9 + 9) / 2 = 9. As all the pixels belong to either region 1, region 2, or both of them, the intensity of every pixel in the result is 9. 
// Please note that the rounded-down values are used when calculating the average of multiple regions, hence the calculation is done using 9 as the average intensity of region 2, not 9.67.
// Example 2:


// Input: image = [[10,20,30],[15,25,35],[20,30,40],[25,35,45]], threshold = 12
// Output: [[25,25,25],[27,27,27],[27,27,27],[30,30,30]]
// Explanation: There exist two regions in the image, which are shown as the shaded areas in the picture. The average intensity of the first region is 25, while the average intensity of the second region is 30. The average intensity of both of the regions is (25 + 30) / 2 = 27.5 which is rounded down to 27. All the pixels in row 0 of the image belong to region 1, hence all the pixels in row 0 in the result are 25. Similarly, all the pixels in row 3 in the result are 30. The pixels in rows 1 and 2 of the image belong to region 1 and region 2, hence their assigned value is 27 in the result.
// Example 3:

// Input: image = [[5,6,7],[8,9,10],[11,12,13]], threshold = 1
// Output: [[5,6,7],[8,9,10],[11,12,13]]
// Explanation: There does not exist any region in image, hence result[i][j] == image[i][j] for all the pixels.

// Leetcode

class Solution {
public:
    vector<vector<int>> resultGrid(vector<vector<int>>& image, int threshold) {
        int m = image.size();
        int n = image[0].size();
        vector<vector<vector<int>>> v(m,vector<vector<int>>(n,vector<int>()));
        int row[2] = {0,1};
        int col[2] = {1,0};
        for(int i=1;i<m-1;i++){
            for(int j=1;j<n-1;j++){
                bool check = true;
                int sum = 0;
                for(int k=i-1;k<=i+1;k++){
                    for(int l=j-1;l<=j+1;l++){
                        sum += image[k][l];
                        for(int x=0;x<2;x++){
                            int ni = k + row[x];
                            int nj = l + col[x];
                            if(ni <= i+1 && nj <= j+1) {
                                if(abs(image[k][l] - image[ni][nj]) > threshold) {
                                    check = false;
                                    break;
                                }
                            }
                        }
                        if(!check) break;
                    }
                    if(!check) break;
                }
                if(check){
                    int avg = sum / 9;
                    for(int k=i-1;k<=i+1;k++){
                        for(int l=j-1;l<=j+1;l++){
                            v[k][l].push_back(avg);
                        }
                    }
                }
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int size = v[i][j].size();
                if(size != 0) {
                    int total = 0;
                    for(auto x : v[i][j]) total += x;
                    image[i][j] = total / size;
                }
            }
        }
        return image;
    }
};