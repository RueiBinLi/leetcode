#include <iostream>
#include <vector>

using namespace std;

class Solution {
    const int MOD = 1e9 + 7;
    public:
        int countGoodNumbers(long long n) {
            return power(5, (n+1)/2) * power(4,n/2) % MOD;
        }

        long long power(long long base, long long exp) {
            long long result = 1;
            while(exp > 0) {
                if(exp % 2 == 1) result = (result * base) % MOD;
                base = (base * base) % MOD;
                exp /= 2;
            }
            return result;
        }
    };

int main(int argc, char* argv[]) {
    Solution sol;
    vector<long long> test_cases = {1, 4, 50};
    for(auto n : test_cases) {
        cout << sol.countGoodNumbers(n) << endl;
    }
    return 0;
}