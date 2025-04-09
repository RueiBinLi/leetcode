#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
    public:
        // Brute Force with bad time complexity
        int minOperations(vector<int>& nums, int k) {
            unordered_set<int> set(nums.begin(), nums.end());
            int count = 0, maxValue;
            while(!set.empty()) {
                maxValue = *max_element(set.begin(), set.end());
                if(maxValue == k && set.size() == 1) break;
                set.erase(maxValue);
                count++;
            }
            if (maxValue >= k) return count;
            return -1;
        }

        // clearer and simplier
        int minOperations_2(vector<int>& nums, int k) {
            unordered_set<int> set(nums.begin(), nums.end());
            int count = 0;
            for(int num : set) {
                if(num < k) return -1;
                else if(num > k) count++;
            }
            return count;
        }
    };

int main(int argc, char* argv[]) {
    Solution sol;
    vector<pair<vector<int>,int>> test_cases = {
        {{5,2,5,4,5},2},
        {{2,1,2},2},
        {{9,7,5,3},1},
    };

    cout << "Method 1:" << endl;
    for(auto& test_case : test_cases) {
        cout << "Minimum operations: " << sol.minOperations(test_case.first, test_case.second) << endl;
    }

    cout << endl << "Method 2:" << endl;
    for(auto& test_case : test_cases) {
        cout << "Minimum operations: " << sol.minOperations_2(test_case.first, test_case.second) << endl;
    }
    return 0;
}