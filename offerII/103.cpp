#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>
#include <limits.h>
#include <extra/utils.hpp>

using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int dp[amount+1];
        memset(dp, 0, sizeof(dp));

        dp[0] = 1;

        for (int k = 1; k <= amount; k++) {
            for (auto const &coin : coins) {
                if (coin <= k && dp[k-coin] != 0) {
                    if (dp[k] == 0) {
                        dp[k] = dp[k-coin]+1;
                    } else {
                        dp[k] = min(dp[k], dp[k-coin]+1);
                    }
                    
                }
            }
        }

        return dp[amount];
    }
};

int main()
{
    string line;
    while (getline(cin, line))
    {
        vector<int> coins = stringToIntegerVector(line);
        getline(cin, line);
        int amount = stringToInteger(line);
        
        int ret = Solution().coinChange(coins, amount);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}