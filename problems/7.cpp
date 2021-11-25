#include <unordered_map>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <extra/utils.hpp>

using namespace std;

class Solution {
public:
    int reverse(int x) {
        int flag = 0;
        string str = to_string(x);
        if (str[0] == '-') {
            str = str.substr(1, str.length());
            flag = 1;
        }
        string rev = string(str.rbegin(), str.rend());
        if (flag == 1) {
            rev += '-'+rev;
        }
        return stoi(rev);
    }
};

int main()
{
    string line;
    while (getline(cin, line))
    {
        int x = stringToInteger(line);
        
        int ret = Solution().reverse(x);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}