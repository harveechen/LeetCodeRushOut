#include <unordered_map>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <extra/utils.hpp>

using namespace std;

class Solution {
public:
    int countSubstrings(string s) {

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