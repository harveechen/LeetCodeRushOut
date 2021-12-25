#include <unordered_map>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <extra/utils.hpp>

using namespace std;

class Solution
{
public:
    int countSubstrings(string s)
    {
        string ext = "^#";
        for (const char &c : s)
        {
            ext += c;
            ext += '#';
        }

        ext += '$';
        vector<int> f(ext.length());

        int iMax = 0, rMax = 0, ans = 0;
        for (int i = 1; i < ext.length() - 1; i++)
        {
            f[i] = (i < iMax) ? min(rMax - i + 1, f[2 * iMax - i]) : 1;
            while (ext[i + f[i]] == ext[i - f[i]])
                ++f[i];
            if (i + f[i] - 1 > rMax)
            {
                iMax = i;
                rMax = i + f[i] - 1;
            }
            ans += (f[i] - 1 + 1) / 2;
        }
        return ans;
    }
};

int main()
{
    string line;
    while (getline(cin, line))
    {
        string s = stringToString(line);

        int ret = Solution().countSubstrings(s);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}