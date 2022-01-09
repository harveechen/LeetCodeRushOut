#include <unordered_map>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <extra/utils.hpp>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> _hash;
        // unordered_map<int, string> exact_match;
        vector<vector<string>> res;
        for (const string& str : strs) {
            string tmp = str;
            sort(tmp.begin(), tmp.end());
            _hash[tmp].push_back(str);
        }

        for (auto& item : _hash) {
            res.push_back(item.second);
        }

        return res;
    }
};

int main()
{
    auto in = vector<string>{"ddddddddddg","dgggggggggg"};
    auto out = Solution().groupAnagrams(in);
}   