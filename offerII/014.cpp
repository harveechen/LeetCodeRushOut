#include <unordered_map>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <extra/utils.hpp>

using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.size();
        vector<int> cnt(26);
        int diff = 0;
        for (auto s : s1) {
            cnt[s-'a']--;
            diff--;
        };
        int i = 0, j = 0;
        int x;
        for (; j < s2.size(); j++) {
            x = s2[j] - 'a';
            cnt[x]++;
            while (cnt[x] > 0)
            {
                cnt[s2[i]-'a']--;
                i++;
            }
            if (j - i + 1 == n)
                return true;
            
        }
        return false;
    }
};

int main()
{
    string line;
    while (getline(cin, line))
    {
        string s1 = stringToString(line);
        getline(cin, line);
        string s2 = stringToString(line);
        
        bool ret = Solution().checkInclusion(s1, s2);

        string out = boolToString(ret);
        cout << out << endl;
    }
    return 0;
}