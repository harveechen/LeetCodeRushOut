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
#include <extra/utils.hpp>

using namespace std;

class Solution {
public:
    int minCut(string s) {
        int n = 2 * s.size() + 1;
        vector<char> ext(n+2, '#');
        for (int i = 0; i < s.size(); i++) {
            ext[2*i+2] = s[i];
        }
        ext[0] = '^', ext[n+1] = '$';

        vector<int> p(n+1, 1);
        int im = 0, rm = 0;
        for (int i = 1; i <= n; i++) {
            if (rm < i) {
                p[i] = 1;
            } else {
                int j = 2 * im - i;
                p[i] = min(p[j], rm - i + 1);
            }

            while (ext[i+p[i]] == ext[i-p[i]]) {
                p[i]++;
            }

            if (i+p[i]-1 > rm) {
                im = i;
                rm = i + p[i] -1;
            }

        }

        vector<int> dp(s.size(), s.size());
        for (int j = 0; j < s.size(); j++) {
            if (isP(p, 0, j)) dp[j] = 0;
            else {
                for (int k = 0; k < j; k++) {
                    if (isP(p, k+1, j)) {
                        dp[j] = min(dp[j], dp[k]+1);
                    }
                }
            }
        }
        return dp.back();
    }

    bool isP(vector<int> &p, int i, int j) {
        int mid = i+j+2;
        int len = p[mid] - 1;
        return j-i+1 <= len;
    }
};

int main()
{
    string line;
    while (getline(cin, line))
    {
        string input = stringToString(line);
        Solution().minCut(input);
    }
    return 0;
}