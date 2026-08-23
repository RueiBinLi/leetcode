#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(), potions.end());

        vector<int> ans(spells.size());

        for (int i = 0; i < spells.size(); i++) {
            int left = 0;
            int right = potions.size() - 1;

            while (left < right) {
                int mid = left + (right - left) / 2;

                long long product = static_cast<long long>(spells[i]) * potions[mid];

                if (product >= success) {
                    right = mid;
                } else {
                    left = mid + 1;
                }
            }

            if (static_cast<long long>(spells[i]) * potions[left] < success) {
                left++;
            }

            ans[i] = potions.size() - left;
        }

        return ans;
    }
};

int main() {
    vector<int> spells = {5, 1, 3};
    vector<int> potions = {1, 2, 3, 4, 5};
    long long success = 7;

    Solution sol;
    vector<int> result = sol.successfulPairs(spells, potions, success);

    for (int x : result) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}