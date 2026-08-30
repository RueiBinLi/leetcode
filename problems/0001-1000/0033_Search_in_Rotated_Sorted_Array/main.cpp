#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool blue(int mid, int end, int target, vector<int>& nums) {
        if (nums[mid] > end) {
            return target > end && nums[mid] >= target;
        } else {
            return target > end || nums[mid] >= target;
        }
    }

    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        int end = nums[right];

        while (left < right) {
            int mid = left + (right - left) / 2;

            if (blue(mid, end, target, nums)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }

        if (nums[left] != target) {
            return -1;
        } else {
            return left;
        }
    }
};

int main() {
    Solution sol;

    vector<int> nums1 = {4, 5, 6, 7, 0, 1, 2};
    int target1 = 0;
    cout << sol.search(nums1, target1) << endl;
    // Expected: 4

    vector<int> nums2 = {4, 5, 6, 7, 0, 1, 2};
    int target2 = 3;
    cout << sol.search(nums2, target2) << endl;
    // Expected: -1

    vector<int> nums3 = {1};
    int target3 = 0;
    cout << sol.search(nums3, target3) << endl;
    // Expected: -1

    vector<int> nums4 = {1};
    int target4 = 1;
    cout << sol.search(nums4, target4) << endl;
    // Expected: 0

    vector<int> nums5 = {3, 1};
    int target5 = 1;
    cout << sol.search(nums5, target5) << endl;
    // Expected: 1

    return 0;
}