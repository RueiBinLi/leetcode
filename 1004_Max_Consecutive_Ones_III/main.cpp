#include <iostream>
#include <vector>

using namespace std;

class Solution {
    public:
        // Method 1 for the first time. Bad time complexity.
        int longestOnes(vector<int>& nums, int k) {
            int max = 0, left = 0, right = 0;
            while(right < nums.size()) {
                if(nums[right] == 1 && k >= 0) {
                    if(max < right-left+1) max = right-left+1;
                    right++;
                } else {
                    if(k > 0) {
                        k--;
                        if(max < right-left+1) max = right-left+1;
                        right++;
                    } else {
                        if(nums[left] == 0) {
                            left++;
                            k++;
                        } else {
                            left++;
                        }
                    }
                }
            }
            return max;
        }

        // Faster
        int longestOnes_fast(vector<int>& nums, int k) {
            int maxLen = 0, left = 0, right = 0, zeroCount = 0;
            while(right < nums.size()) {
                if(nums[right] == 0) {
                    zeroCount++;
                }
                if(zeroCount > k) {
                    if(nums[left] == 0) zeroCount--;
                    left++;
                }
                maxLen = max(maxLen, right-left+1);
                right++;
            }
            return maxLen;
        }
    };

int main(int argc, char* argv[]) {
    Solution sol;
    vector<pair<vector<int>, int>> test_cases = {
        {{1,1,1,0,0,0,1,1,1,1,0}, 2},
        {{0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1}, 3},
        {{1,0,1,0,1}, 2},
        {{0,0,0}, 2},
        {{1,1,1}, 2}
    };

    cout << "Method 1:" << endl;
    for(auto& test_case : test_cases) {
        cout << sol.longestOnes(test_case.first, test_case.second) << endl;
    }

    cout << endl << "Method 2:" << endl;
    for(auto& test_case : test_cases) {
        cout << sol.longestOnes_fast(test_case.first, test_case.second) << endl;
    }

    return 0;
}