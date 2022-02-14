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

class Solution
{
public:
    string solution(string &S, string &T)
    {
        // write your code in C++14 (g++ 6.2.0)
        int n = S.size();
        int m = T.size();

        if (n != m)
        {
            if (n + 1 == m)
            {
                for (int k = m - 1; k > 0; k--)
                {
                    if (S[k - 1] != T[k])
                        return "IMPOSSIBLE";
                }
                return "INSERT " + T.substr(0, 1);
            }
        } else {
            int cnt = 0;
            vector<pair<string, string>> ret;
            for (int k = 0; k < n; k++) {
                if (S[k] != T[k]) {
                    cnt++;
                    ret.emplace_back(S.substr(k, 1), T.substr(k, 1));
                }
            }
            if (cnt == 0) return "NOTHING";
            if (cnt == 1) {
                return "CHANGE " + ret[0].first + " " + ret[0].second;
            }
            if (cnt == 2) {
                if (ret[0].first == ret[1].second && ret[0].second == ret[1].first) {
                    return "SWAP " + ret[0].first + " " + ret[0].second;
                }
            }
        }
        return "IMPOSSIBLE";
    }
};

int main()
{
    string a = "";
    string b = "a";
    cout << Solution().solution(a, b) << endl;
    ;
    return 0;
}