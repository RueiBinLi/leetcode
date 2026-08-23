#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
    public:
        int compress(vector<char>& chars) {
            int i = 1, right = 1, left = 0;
            char character;
            while(i < chars.size()) {
                character = chars[i-1];
                while(character == chars[right]) right++;
                while(character != chars[left]) left++;
                int right_index = right;
                for(int j = left+1; j < right_index; j++) {
                    chars.erase(chars.begin()+left+1);
                    right--;
                }
                if(right_index-left > 1) {
                    if(right_index-left <= 9) {
                        chars.insert(chars.begin()+left+1, right_index-left + '0');
                        i = left+2;
                    }
                    else {
                        string num = to_string(right_index-left);
                        for(int j = 0; j < num.size(); j++) {
                            chars.insert(chars.begin()+left+1+j, num[j]);
                        }
                        i = left+1+num.size();
                    }
                } else i = left+2;
            }
            return chars.size();
        }
    };

int main(int argc, char* argv[]) {
    Solution sol;
    vector<vector<char>> test_cases = {
        // {'a','a','b','b','c','c','c'},
        // {'a'},
        // {'a','b','b','b','b','b','b','b','b','b'},
        // {'a','a','a','a'},
        {'a','a','a','b','b','a','a'},
    };

    for(auto& test_case : test_cases) {
        cout << "Compressed size: " << sol.compress(test_case) << endl;
    }
    return 0;
}