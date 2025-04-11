#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
    public:
        int countSymmetricIntegers(int low, int high) {
            int count = 0;
            for(int left = low; left <= high; left++) {
                string str = to_string(left);
                int str_len = str.size();
    
                int left_half = 0, right_half = 0;
                if(str_len % 2 == 0) {
                    for(int i = 0; i < str_len/2; i++) {
                        left_half += str[i] - '0';
                    }
                    for(int i = str_len/2; i < str_len; i++) {
                        right_half += str[i] - '0';
                    }
    
                    if(left_half == right_half) count++;
                }
            }
    
            return count;
        }
    };

int main(int argc, char* argv[]) {
    Solution sol;
    vector<pair<int, int>> testCases = {
        {1, 100},
        {1200, 1230},
        {1, 10000}
    };

    for(auto& testCase : testCases) {
        cout << sol.countSymmetricIntegers(testCase.first, testCase.second) << endl;
    }

    return 0;
}