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
#include <limits.h>
#include <stdio.h>
#include <string.h>
#include <extra/utils.hpp>

using namespace std;

class Solution {
public:
    int numDistinct(string s, string t) {
        int len_s = s.size();
        int len_t = t.size();

        int dp[len_s+1][len_t+1];
        for (int k = 0; k <= len_s; k++) {
            dp[k][0] = 1;
        }

        for (int k = 1; k <= len_t; k++) {
            dp[0][k] = 0;
        }

        for (int i = 1; i <= len_s; i++) {
            for (int j = 1; j <= len_t; j++) {
                if (s[i-1] == t[j-1]) {
                    dp[i][j] = dp[i-1][j] + dp[i-1][j-1];
                } else {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }

        return dp[len_s][len_t];
    }
};

int main()
{
    string line;
    while (getline(cin, line))
    {
        string s = stringToString(line);
        getline(cin, line);
        string t = stringToString(line);
        
        int ret = Solution().numDistinct(s, t);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}