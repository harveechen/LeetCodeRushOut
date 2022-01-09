#include <unordered_map>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <extra/utils.hpp>

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;
        vector<int> _hash(26, 0);
        int cnt = 0;
        bool is_same = true;
        for (int i = 0; i < s.size(); i++) {
            if (is_same && s[i] != t[i]) is_same = false;
            if (_hash[s[i]-'a'] == 0) cnt++;
            _hash[s[i]-'a']++;
        }

        if (is_same) return false;

        for (const char & ch : t) {
            _hash[ch-'a']--;
            if (_hash[ch-'a'] == 0) cnt--;
        }

        return cnt == 0;
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
        
        bool ret = Solution().isAnagram(s, t);

        string out = boolToString(ret);
        cout << out << endl;
    }
    return 0;
}