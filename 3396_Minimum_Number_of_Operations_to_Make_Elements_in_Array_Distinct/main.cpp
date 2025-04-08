#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
    public:
        int minimumOperations(vector<int> nums) {
            unordered_set<int> set(nums.begin(), nums.end());
            bool distinct = false;
            int op = 0;
            if(set.size() == nums.size()) distinct = true;
            while(!distinct) {
                if(nums.size() >= 3) for(int i = 0; i < 3; i++) nums.erase(nums.begin());
                else for(int i = 0; i < nums.size(); i++) nums.erase(nums.begin());
                set.clear();
                set.insert(nums.begin(), nums.end());
                if(nums.size() == set.size()) distinct = true;
                op++;
            }
            return op;
        }

        // Find the index that the number repeats from back
        int minimumOperations_greedy(vector<int> nums) {
            vector<int> mpp(101);
            for(int i = nums.size()-1; i >= 0; i--) {
                if(++mpp[nums[i]] > 1) return (i+3)/3;
            }
            return 0;
        }
    };

int main(int argc, char* argv[]) {
    Solution sol;
    vector<vector<int>> test_cases = {
        {1,2,3,4,2,3,3,5,7},
        {4,5,6,4,4},
        {6,7,8,9},
    };

    cout << "Brute Force:" << endl;
    for(auto& test_case : test_cases) {
        cout << "Minimum operations: " << sol.minimumOperations(test_case) << endl;
    }

    cout << endl << "Greedy:" << endl;
    for(auto& test_case : test_cases) {
        cout << "Minimum operations: " << sol.minimumOperations_greedy(test_case) << endl;
    }
    return 0;
}