#include <iostream>
#include <math.h>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp(text1.size()+1, vector<int>(text2.size()+1));
        for (int i = 0; i < text1.size()+1; ++i) {
            dp[i][0] = 0;
        }
        for (int i = 0; i < text2.size()+1; ++i) {
            dp[0][i] = 0;
        }

        for (int i = 1; i < text1.size()+1; ++i) {
            for (int j = 1; j < text2.size()+1; ++j) {
                if (text1[i-1] == text2[j-1]) {
                    dp[i][j] = dp[i-1][j-1] + 1;
                } else {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }

        return dp[text1.size()][text2.size()];
    }
};


int main() {
    Solution solution;

    // LeetCode Example 1
    string text1 = "abcde";
    string text2 = "ace";

    cout << "Test 1" << endl;
    cout << "text1 = " << text1 << endl;
    cout << "text2 = " << text2 << endl;
    cout << "Expected: 3" << endl;
    cout << "Output: "
         << solution.longestCommonSubsequence(text1, text2)
         << endl;

    cout << "--------------------" << endl;

    // LeetCode Example 2
    text1 = "abc";
    text2 = "abc";

    cout << "Test 2" << endl;
    cout << "text1 = " << text1 << endl;
    cout << "text2 = " << text2 << endl;
    cout << "Expected: 3" << endl;
    cout << "Output: "
         << solution.longestCommonSubsequence(text1, text2)
         << endl;

    cout << "--------------------" << endl;

    // LeetCode Example 3
    text1 = "abc";
    text2 = "def";

    cout << "Test 3" << endl;
    cout << "text1 = " << text1 << endl;
    cout << "text2 = " << text2 << endl;
    cout << "Expected: 0" << endl;
    cout << "Output: "
         << solution.longestCommonSubsequence(text1, text2)
         << endl;

    return 0;
}