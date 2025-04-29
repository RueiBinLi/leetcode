#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int left = 0, maximum = *max_element(nums.begin(), nums.end());
        long long count = 0, ans = 0;

        for(int right = 0; right < nums.size(); right++) {
            if(nums[right] == maximum) count++;
            while(count == k) {
                ans += nums.size() - right;
                if(nums[left] == maximum) count--;
                left++;
            }
        }

        return ans;
    }
};

int main(int argc, char* argv[]) {
    Solution sol;
    vector<pair<vector<int>, int>> testCases = {
        {{1,3,2,3,3}, 2},
        {{1,4,2,1}, 3},
    };

    for(auto& arr : testCases) {
        long long result = sol.countSubarrays(arr.first, arr.second);
        cout << result << endl;
    }

    return 0;
}