#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size(), 1);

        for (int i = 1; i < nums.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[j] < nums[i]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }

        return *max_element(dp.begin(), dp.end());
    }
};

int main() {
    Solution solution;

    // LeetCode Example 1
    vector<int> nums1 = {10, 9, 2, 5, 3, 7, 101, 18};
    cout << "Test 1" << endl;
    cout << "Expected: 4" << endl;
    cout << "Output: " << solution.lengthOfLIS(nums1) << endl;

    cout << "--------------------" << endl;

    // LeetCode Example 2
    vector<int> nums2 = {0, 1, 0, 3, 2, 3};
    cout << "Test 2" << endl;
    cout << "Expected: 4" << endl;
    cout << "Output: " << solution.lengthOfLIS(nums2) << endl;

    cout << "--------------------" << endl;

    // LeetCode Example 3
    vector<int> nums3 = {7, 7, 7, 7, 7, 7, 7};
    cout << "Test 3" << endl;
    cout << "Expected: 1" << endl;
    cout << "Output: " << solution.lengthOfLIS(nums3) << endl;

    return 0;
}