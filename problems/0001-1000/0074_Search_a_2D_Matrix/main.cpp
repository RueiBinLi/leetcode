#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = static_cast<int>(matrix.size());
        int n = static_cast<int>(matrix[0].size());
        int full_size = m*n;
        int left = 0;
        int right = full_size;

        while (left < right) {
            int mid = left + (right - left) / 2;
            int row = mid / n;
            int col = mid % n;

            if (matrix[row][col] < target) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        
        int row = left / n;
        int col = left % n;
        if ((row < m && col < n) && matrix[row][col] == target) {
            return true;
        } else {
            return false;
        }
    }
};

int main() {
    Solution sol;

    vector<vector<int>> matrix1 = {
        {1, 3, 5, 7},
        {10, 11, 16, 20},
        {23, 30, 34, 60}
    };

    int target1 = 3;
    cout << sol.searchMatrix(matrix1, target1) << endl;
    // Expected: 1 / true

    int target2 = 13;
    cout << sol.searchMatrix(matrix1, target2) << endl;
    // Expected: 0 / false

    int target3 = 60;
    cout << sol.searchMatrix(matrix1, target3) << endl;
    // Expected: 1 / true

    int target4 = 61;
    cout << sol.searchMatrix(matrix1, target4) << endl;
    // Expected: 0 / false
    // 這個 case 你的程式目前可能會 out of bounds

    vector<vector<int>> matrix2 = {
        {1}
    };

    int target5 = 1;
    cout << sol.searchMatrix(matrix2, target5) << endl;
    // Expected: 1 / true

    int target6 = 2;
    cout << sol.searchMatrix(matrix2, target6) << endl;
    // Expected: 0 / false
    // 這個 case 你的程式目前也可能會 out of bounds

    return 0;
}