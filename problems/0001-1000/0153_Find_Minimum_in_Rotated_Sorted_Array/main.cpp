#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;

        while (left < right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] > nums[nums.size() - 1]) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }

        return nums[right];
    }
};

int main() {
    Solution sol;

    vector<int> nums1 = {3, 4, 5, 1, 2};
    cout << sol.findMin(nums1) << endl;
    // Expected: 1

    vector<int> nums2 = {4, 5, 6, 7, 0, 1, 2};
    cout << sol.findMin(nums2) << endl;
    // Expected: 0

    vector<int> nums3 = {11, 13, 15, 17};
    cout << sol.findMin(nums3) << endl;
    // Expected: 11

    vector<int> nums4 = {2, 1};
    cout << sol.findMin(nums4) << endl;
    // Expected: 1

    return 0;
}