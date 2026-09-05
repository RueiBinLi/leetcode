#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        vector<int> ans;
        int m = mat.size();
        int n = mat[0].size();
        int left = 0;
        int right = n-1;
        while(left <= right) {
            int mid = left + (right - left) / 2;
            int max = mat[0][mid];
            int max_row = 0;
            int i = 1;
            while (i < m) {
                if (max < mat[i][mid]) {
                    max = mat[i][mid];
                    max_row = i;
                }
                i++;
            }
            int leftval = mid - 1 >= 0 ? mat[max_row][mid-1] : -1;
            int rightval = mid + 1 < n ? mat[max_row][mid+1] : -1;
            int cur = mat[max_row][mid];
            if (cur < leftval) {
                right = mid-1;
            } else if (cur < rightval) {
                left = mid+1;
            } else {
                return {max_row, mid};
            }
        }
        return {-1, -1};

        // Wrong Answer. When I found the first 1D peak, if it is not a 2D peak, I will skip the row. It may be other peak in the same row
        // for (int i = 0; i < m; i++) {
        //     int left = 0;
        //     int right = n - 1;

        //     while (left < right) {
        //         int mid = left + (right - left) / 2;

        //         if (mat[i][mid] < mat[i][mid + 1]) {
        //             left = mid + 1;
        //         } else {
        //             right = mid;
        //         }
        //     }

        //     bool max = true;

        //     for (int j = 0; j < 2; j++) {
        //         int new_x = i + dx[j];
        //         int new_y = left + dy[j];

        //         if (new_x < 0 || new_x >= m) continue;

        //         cout << new_x << ", " << new_y << endl;

        //         if (mat[i][left] < mat[new_x][new_y]) {
        //             max = false;
        //         }
        //     }

        //     if (max) return {i, left};
        // }

        // return {0, 0};
    }
};

int main() {
    Solution sol;

    vector<vector<int>> mat1 = {
        {1, 4},
        {3, 2}
    };

    vector<int> result1 = sol.findPeakGrid(mat1);
    cout << "Result 1: [" << result1[0] << ", " << result1[1] << "]" << endl;
    // Expected: [0, 1] or [1, 0]

    vector<vector<int>> mat2 = {
        {10, 20, 15},
        {21, 30, 14},
        {7, 16, 32}
    };

    vector<int> result2 = sol.findPeakGrid(mat2);
    cout << "Result 2: [" << result2[0] << ", " << result2[1] << "]" << endl;
    // Expected: [1, 1] or [2, 2]

    vector<vector<int>> mat3 = {
        {1, 2, 3, 6, 5},
        {16, 41, 23, 22, 6},
        {15, 17, 24, 21, 7},
        {14, 18, 19, 20, 10},
        {13, 14, 11, 10, 9}
    };

    vector<int> result3 = sol.findPeakGrid(mat3);
    cout << "Result 3: [" << result3[0] << ", " << result3[1] << "]" << endl;
    // Expected: any valid peak, for example [1, 1] or [2, 2]

    //[[92,91,57],[98,24,34]]

    vector<vector<int>> mat4 = {
        {92, 91, 57},
        {98, 24, 34}
    };

    vector<int> result4 = sol.findPeakGrid(mat4);
    cout << "Result 4: [" << result4[0] << ", " << result4[1] << "]" << endl;

    return 0;
}