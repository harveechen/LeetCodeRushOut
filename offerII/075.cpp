#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <limits.h>
#include <extra/utils.hpp>

using namespace std;

class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<int, int> _map;
        for (int i = 0; i < arr2.size(); i++) {
            _map[arr2[i]] = i;
        }

        struct CMP {
            private:
            unordered_map<int, int> _map;
            public:
            CMP(unordered_map<int, int> &map): _map(map) {};
            bool operator()(int &lh, int &rh) {
                auto it_l = _map.find(lh);
                auto it_r = _map.find(rh);

                if (it_l == _map.end() && it_r == _map.end()) {
                    return lh < rh;
                } else if (it_l == _map.end()) {
                    return false;
                } else if (it_r == _map.end()) {
                    return true;
                } else {
                    return it_l->second < it_r->second;
                }
            }
        };
        
        auto cmp = CMP(_map);
        sort(arr1.begin(), arr1.end(), cmp);
        return arr1;
    }
};

int main()
{
    string line;
    while (getline(cin, line))
    {
        vector<int> arr1 = stringToIntegerVector(line);
        getline(cin, line);
        vector<int> arr2 = stringToIntegerVector(line);
        
        vector<int> ret = Solution().relativeSortArray(arr1, arr2);

        string out = integerVectorToString(ret);
        cout << out << endl;
    }
    return 0;
}