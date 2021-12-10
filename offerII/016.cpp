#include <unordered_map>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <extra/utils.hpp>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxlen = 0;
        int x;
        int i = 0;
        vector<int> cnt(96);
        for (int j = 0; j < s.size(); j++) {
            x = s[j] - ' ';
            cnt[x]++;
            while (cnt[x] > 1) {
                cnt[s[i]-' ']--;
                i++;
            }
            if (j-i+1 > maxlen) {
                maxlen = j-i+1;
            }
        }
        return maxlen;
    }
};

int main()
{
    string line;
    while (getline(cin, line))
    {
        string s = stringToString(line);
        
        int ret = Solution().lengthOfLongestSubstring(s);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}

/*
title: 剑指 Offer II 016. 不含重复字符的最长子字符串
content: 给定一个字符串 s ，请你找出其中不含有重复字符的 最长连续子字符串 的长度。

input: "abcabcbb"
output: 3
*/

/* 
ascii code
~  control code
32 space
48 0
65 A
97 a
 */