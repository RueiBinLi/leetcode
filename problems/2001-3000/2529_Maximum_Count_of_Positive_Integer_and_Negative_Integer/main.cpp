#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int neg_left = 0;
        int pos_left = 0;
        int neg_right = nums.size();
        int pos_right = nums.size();

        while (neg_left < neg_right) {
            int mid = neg_left + (neg_right - neg_left) / 2;

            if (nums[mid] < 0) {
                neg_left = mid + 1;
            } else {
                neg_right = mid;
            }
        }

        while (pos_left < pos_right) {
            int mid = pos_left + (pos_right - pos_left) / 2;

            if (nums[mid] > 0) {
                pos_right = mid;
            } else {
                pos_left = mid + 1;
            }
        }

        return max(neg_left, static_cast<int>(nums.size()) - pos_left);
    }
};

int main() {
    Solution sol;

    vector<int> nums1 = {-2, -1, -1, 1, 2, 3};
    cout << sol.maximumCount(nums1) << endl; 
    // Expected: 3

    vector<int> nums2 = {-3, -2, -1, 0, 0, 1, 2};
    cout << sol.maximumCount(nums2) << endl;
    // Expected: 3

    vector<int> nums3 = {5, 20, 66, 1314};
    cout << sol.maximumCount(nums3) << endl;
    // Expected: 4

    vector<int> nums4 = {-5, -4, -3, -2, -1};
    cout << sol.maximumCount(nums4) << endl;
    // Expected: 5

    vector<int> nums5 = {0, 0, 0};
    cout << sol.maximumCount(nums5) << endl;
    // Expected: 0

    return 0;
}