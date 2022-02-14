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
#include <sstream>
#include <iterator>
#include <limits.h>
#include <extra/utils.hpp>

using namespace std;

class Solution {
public:
    vector<string> path;
    vector<string> res;
    void backtrace(string &s, int idx) {
        if (path.size() == 4) {
            if (idx >= s.size()) {
            string out;
            for (auto p : path) {
                out += p;
                out += ".";
            }
            out.erase(out.end()-1);
            res.push_back(out);
            }
            return;
        }
        
        if (int(s.size()- idx - 3 * (4-path.size())) > 0) {
            return;
        }

        for (int i = 0; i < min(3, (int)s.size()-idx); i++) {
            string tmp = s.substr(idx, i+1);
            if (!check(tmp)) continue;
            path.push_back(tmp);
            backtrace(s, idx+i+1);
            path.pop_back();
        }

    }

    inline bool check(string &s) {
        int tmp = stoi(s);
        if (s.size() > 1 && s.at(0) == '0' || tmp > 255) return false;
        return true;
    }
    vector<string> restoreIpAddresses(string s) {
        backtrace(s, 0);
        return res;
    }
};

int main()
{
    string line;
    while (getline(cin, line))
    {
        string input = stringToString(line);
        vector<string> ans = Solution().restoreIpAddresses(input);
    }
    return 0;
}