#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;

        while (left < right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] < nums[mid + 1]) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }

        return left;
    }
};

int main() {
    Solution sol;

    vector<int> nums1 = {1, 2, 3, 1};
    int result1 = sol.findPeakElement(nums1);
    cout << "Peak index: " << result1 << endl;
    cout << "Peak value: " << nums1[result1] << endl;
    // Expected index: 2, value: 3

    vector<int> nums2 = {1, 2, 1, 3, 5, 6, 4};
    int result2 = sol.findPeakElement(nums2);
    cout << "Peak index: " << result2 << endl;
    cout << "Peak value: " << nums2[result2] << endl;
    // Expected index: 1 or 5, value: 2 or 6

    return 0;
}