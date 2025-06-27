#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    string longestSubsequenceRepeatedK(string s, int k) {
        int n = s.size();
        vector<int> freq(26, 0);
        for(char c : s) {
            freq[c - 'a']++;
        }
        vector<char> candidate;
        for(int i = 25; i >= 0; i--) {
            if(freq[i] >= k) candidate.push_back('a' + i);
        }
        queue<string> q;
        for(char c : candidate) {
            q.push(string(1, c));
        }

        string ans = "";
        while(!q.empty()) {
            string curr = q.front();
            q.pop();
            if (curr.size() > ans.size()) {
                ans = curr;
            }
            for(char c : candidate) {
                string next = curr + c;
                if(isK(s, next, k)) {
                    q.push(next);
                }
            }
        }

        return ans;
    }

    bool isK(string s, string next, int k) {
        int i = 0, count = 0;
        for(char c : s) {
            if(c == next[i]) {
                if(++i == next.size()) {
                    i = 0;
                    if(++count == k) return true;
                }
            }
        }
        return false;
    }
};

int main(int argc, char* argv[]) {
    Solution sol;
    vector<pair<string, int>> test_cases = {
        {"letsleetcode", 2},
        {"bb", 2},
        {"ab", 2},
        {"bab", 2},
        {"ab", 2},
        {"aaabbbcccddd", 3},
        {"abcabcabc", 3},
        {"aabbcc", 2}
    };

    for(const auto& test_case : test_cases) {
        cout << sol.longestSubsequenceRepeatedK(test_case.first, test_case.second) << endl;
    }

    return 0;
}