#include <unordered_map>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <extra/utils.hpp>

using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n = p.size();
        vector<int> cnt(26);
        for (auto s : p) {
            cnt[s-'a']--;
        };
        int i = 0, j = 0;
        int x;
        vector<int> res;
        for (; j < s.size(); j++) {
            x = s[j] - 'a';
            cnt[x]++;
            while (cnt[x] > 0)
            {
                cnt[s[i]-'a']--;
                i++;
            }
            if (j - i + 1 == n)
                res.push_back(i);  
        }
        return res;
    }
};

int main()
{
    string line;
    while (getline(cin, line))
    {
        string s = stringToString(line);
        getline(cin, line);
        string p = stringToString(line);
        
        vector<int> ret = Solution().findAnagrams(s, p);

        string out = integerVectorToString(ret);
        cout << out << endl;
    }
    return 0;
}