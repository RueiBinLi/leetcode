#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
    public:
        int lengthOfLongestSubstring(string s) {
            int left = 0, ans = 0;
            unordered_set<char> set;
            for(int right = 0; right < s.size(); right++) {
                while(set.find(s[right]) != set.end()) {
                    set.erase(s[right]);
                    left++;
                }
                set.insert(s[right]);
                ans = max(ans, right-left+1);
            }
            return ans;
        }
};

int main(int argc, char* argv[]) {
    Solution sol;
    vector<string> test_cases = {
        "abcabcbb",
        "bbbbb",
        "pwwkew",
        "",
        "dvdf",
        "aab",
        "abba",
        "tmmzuxt"
    };

    for(const auto& test_case : test_cases) {
        cout << sol.lengthOfLongestSubstring(test_case) << endl;
    }

    return 0;
}