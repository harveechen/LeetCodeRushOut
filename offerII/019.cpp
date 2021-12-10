#include <unordered_map>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <extra/utils.hpp>

using namespace std;

class Solution {
public:
    bool validPalindrome(string s) {
        for (int i = 0, j = s.size() - 1; i < j; i++, j--) {
            if (s[i] != s[j]) {
                return validPalindrome(s, ++i, j) || validPalindrome(s, --i, --j);
            }
        }
        return true;
    }

    bool validPalindrome(string &s, int left, int right) {
        while (left < right) {
            if (s[left++] != s[right--])
                return false;
        }
        return true;
    }
};

int main()
{
    string line;
    while (getline(cin, line))
    {
        string s = stringToString(line);
        
        bool ret = Solution().validPalindrome(s);

        string out = boolToString(ret);
        cout << out << endl;
    }
    return 0;
}