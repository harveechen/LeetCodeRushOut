#include <unordered_map>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <extra/utils.hpp>

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        int i = 0, j = s.size() - 1;
        int x, y;
        while (i < j) {
            x = char2int(s[i]);
            if (x < 0) {
                i++;
                continue;
            }
            y = char2int(s[j]);
            if (y < 0) {
                j--;
                continue;
            }
            if (x == y) {
                i++;
                j--;
            } else {
                return false;
            }
            
        }
        return true;
    }

    int char2int(char c) {
        if (c >= 48 && c < 58) {
            return c - '0';
        }
        if (c > 64 && c <= 90) {
            return c - 'A' + 10;
        }

        if (c > 96 && c <= 122) {
            return c - 'a' + 10;
        }

        return -1;
    }
};

int main()
{
    string line;
    while (getline(cin, line))
    {
        string s = stringToString(line);
        
        bool ret = Solution().isPalindrome(s);

        string out = boolToString(ret);
        cout << out << endl;
    }
    return 0;
}