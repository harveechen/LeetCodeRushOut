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
    vector<string> path;
    vector<vector<string>> res;
    vector<vector<string>> partition(string s) {
        backtrace(s, 0);
        return res;
    }

    void backtrace(string &s, int idx) {
        if (idx < s.size()) {
            int n = 0;
            while  (++n && idx + n <= s.size()) {
                string tmp = s.substr(idx, n);
                if (!check(tmp)) continue;
                path.push_back(tmp);
                backtrace(s, idx + n);
                path.pop_back();
            }
        } else {
            res.push_back(path);
        }
    }

    bool check(string &s) {
        for (int i = 0, j = s.size() - 1; i < j; i++, j--) {
            if (s[i] != s[j]) return false;
        }
        return true;
    }
};

int main()
{
    string line;
    while (getline(cin, line))
    {
        string input = stringToString(line);
        Solution().partition(input);
    }
    return 0;
}