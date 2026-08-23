#include <iostream>
#include <vector>

using namespace std;

class Solution {
    public:
        // Brute force O(n^3) solution
        int countGoodTriplets(vector<int>& arr, int a, int b, int c) {
            int count = 0;
            for(int i = 0; i < arr.size()-2; i++) {
                for(int j = i + 1; j < arr.size()-1; j++) {
                    for(int k = j + 1; k < arr.size(); k++) {
                        if(abs(arr[i]-arr[j]) <= a && abs(arr[j]-arr[k]) <= b && abs(arr[i]-arr[k]) <= c) count++;
                    }
                }
            }
            return count;
        }
    };

int main(int argc, char* argv[]) {
    Solution sol;
    vector<pair<vector<int>, vector<int>>> testCases = {
        {{3,0,1,1,9,7}, {7,2,3}},
        {{1,1,2,2,3}, {0,0,1}},
        {{0,0,0}, {0,0,0}},
        {{1,2,3}, {1,1,1}},
        {{5,4,3}, {2,2,2}}
    };
    int a = 1, b = 2, c = 3;

    for(auto& arr : testCases) {
        int result = sol.countGoodTriplets(arr.first, arr.second[0], arr.second[1], arr.second[2]);
        cout << result << endl;
    }

    return 0;
}