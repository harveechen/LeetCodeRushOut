#include <unordered_map>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <extra/utils.hpp>

using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        if (s.length() < t.length()) return "";
        unordered_map<char, int> map;
        int cnt = 0;
        int minlen = t.length() + 1;

        for (const char &ch : t) {
            if (map.count(ch)) {
                map[ch]++;
            } else {
                map[ch] = 1;
                cnt++;
            }
        }
        
        int left = 0, right = 0;
        int minleft;
        while (right <= s.length() && minlen != t.size()) {
            if (cnt > 0) {
                right++;
                if (map.count(s[right-1])) {
                    map[s[right-1]]--;
                    if (map[s[right-1]] == 0) {
                        cnt--;
                    }
                }
            } else {
                int cur = right - left;
                if (cur < minlen) {
                    minlen = cur;
                    minleft = left;
                }

                if (map.count(s[left])) {
                    map[s[left]]++;
                    if (map[s[left]] == 1) {
                        cnt++;
                    }
                }
                left++;
            }
        }

        return minlen 
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
        
        string ret = Solution().minWindow(s, t);

        string out = (ret);
        cout << out << endl;
    }
    return 0;
}