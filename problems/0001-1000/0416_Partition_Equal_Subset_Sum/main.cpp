#include <iostream>
#include <vector>

using namespace std;

class Solution {
    public:
        bool canPartition(vector<int>& nums) {
            int sum = 0, targetSum;
            for(int num : nums) sum += num;
            if(sum % 2 != 0) return false;
            else targetSum = sum / 2;
    
            vector<bool> dp(targetSum + 1, false);
            dp[0] = true;
            for(int num : nums){
                for(int currSum = targetSum; currSum >= num; currSum--) {
                    dp[currSum] = dp[currSum] || dp[currSum - num];
                    if(dp[targetSum]) return true;
                }
            }
            
            return dp[targetSum];
        }
    };

int main(int argc, char* argv[]) {
    Solution sol;
    vector<vector<int>> testCases = {
        {1, 5, 11, 5},
        {1, 2, 3, 5},
        {1, 2, 3, 4}
    };

    for(auto& nums : testCases) {
        cout << (sol.canPartition(nums) ? "true" : "false") << endl;
    }

    return 0;
}