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
#include <string.h>

using namespace std;

int solution(string &str) {
    // int cnt0 = 0, cnt1 = 0;
    int n = str.size();
    if (n == 1) return 0;
    // for (int i = 0; i < n; i++) {
    //     char ch = str[i];
    //     if (ch == '0') cnt0 = 1;
    //     else cnt1 = 1;
    //     if (cnt1 && cnt0) break;
    // }

    int maxLen = 1;
    int dp[n][n];
    int cnt0[n][n];
    int cnt1[n][n];
    memset(cnt0, 0, sizeof(cnt0));
    memset(cnt1, 0, sizeof(cnt1));
    for (int i = 0; i < n; i++) {
        dp[i][i] = 1;
        if (str[i] == '0') cnt0[i][i] = 1;
        else cnt1[i][i] = 1;
    }
    for (int L = 2; L <= n; L++) {
        for (int i = 0; i < n; i++) {
            int j = i + L - 1;
            if (L > 2) {
                cnt0[i][j] = cnt0[i+1][j-1];
                cnt1[i][j] = cnt1[i+1][j-1];
            }
            if (str[i] == '0') cnt0[i][j] += 1;
            else cnt1[i][j] += 1;

            if (str[j] == '0') cnt0[i][j] += 1;
            else cnt1[i][j] += 1;

            if (j >= n) break;

            if (str[i] != str[j]) {
                dp[i][j] = false;
            } else {
                if (L <= 2) dp[i][j] = true;
                else dp[i][j] = dp[i+1][j-1];
            }

            if (dp[i][j] && cnt0[i][j] && cnt1[i][j] && L > maxLen) maxLen = L;
        }
    }

    return maxLen == 1 ? 0 : maxLen;
}


int main()
{
    string line;
    getline(cin, line);
    cout << solution(line) << endl;
    return 0;
}