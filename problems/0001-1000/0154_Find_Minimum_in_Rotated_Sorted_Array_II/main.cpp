#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int len = nums.size();
        int left = 0;
        int right = len - 1;

        while (left < right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] < nums[right]) {
                right = mid;
            } else if (nums[mid] > nums[right]) {
                left = mid + 1;
            } else {
                right--;
            }
        }

        return nums[left];
    }
};

int main() {
    Solution sol;

    vector<int> nums1 = {1, 3, 5};
    cout << sol.findMin(nums1) << endl;
    // Expected: 1

    vector<int> nums2 = {2, 2, 2, 0, 1};
    cout << sol.findMin(nums2) << endl;
    // Expected: 0

    vector<int> nums3 = {10, 1, 10, 10, 10};
    cout << sol.findMin(nums3) << endl;
    // Expected: 1

    vector<int> nums4 = {3, 3, 1, 3};
    cout << sol.findMin(nums4) << endl;
    // Expected: 1

    vector<int> nums5 = {1, 1, 1, 1};
    cout << sol.findMin(nums5) << endl;
    // Expected: 1

    return 0;
}