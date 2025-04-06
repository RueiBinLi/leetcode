#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution {
    public:
        vector<int> largestDivisibleSubset(vector<int>& nums) {
            sort(nums.begin(), nums.end());
            vector<int> dp(nums.size(), 1), prev(nums.size(), -1);
            int max_index = 0;
            for(int i = 1; i < nums.size(); i++) {
                for(int j = 0; j < i; j++) {
                    if(nums[i] % nums[j] == 0 && dp[i] < dp[j] + 1) {
                        dp[i] = dp[j] + 1;
                        prev[i] = j;
                    }
                }
                if(dp[i] > dp[max_index]) max_index = i;
            }

            vector<int> result;
            for(int i = max_index; i >= 0; i = prev[i]) result.insert(result.begin(), nums[i]);
            return result;
        }
    };

int main(int argc, char* argv[]) {
    Solution sol;
    vector<vector<int>> testCases = {
        {1, 2, 3},
        {1, 2, 4, 8},
        {1, 2, 3, 4, 6}
    };

    for(auto& nums : testCases) {
        vector<int> result = sol.largestDivisibleSubset(nums);
        for(auto& num : result) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}