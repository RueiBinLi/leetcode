#include <iostream>
#include <vector>

using namespace std;

class Solution {
    public:
        int findNumbers(vector<int>& nums) {
            int count = 0;
            for(int num : nums) {
                string str = to_string(num);
                if(str.size() % 2 == 0) count++;
            }
            return count;
        }
    };

int main(int argc, char* argv[]) {
    Solution sol;
    vector<vector<int>> test_cases = {
        {12, 345, 2, 6, 7896},
        {555, 901, 482, 1771},
        {1, 22, 3333, 44444},
        {1234, 5678, 91011},
    };

    for(auto& test_case : test_cases) {
        cout << sol.findNumbers(test_case) << endl;
    }
    return 0;
}