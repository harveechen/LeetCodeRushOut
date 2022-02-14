#include <unordered_map>
#include <unordered_set>
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
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        set<int> iset;
        for (int i = 0; i < nums.size(); i++) {
            auto it = iset.lower_bound(max(nums[i], INT_MIN+t) - t);
            if (it != iset.end() && *it <= (min(nums[i], INT_MAX-t)+t)) {
                return true;
            }

            iset.insert(nums[i]);
            if (i >= k) {
                iset.erase(nums[i-k]);
            }
            
        }
        return false;
    }
};

int main()
{
    string line;
    while (getline(cin, line))
    {
        vector<int> nums = stringToIntegerVector(line);
        getline(cin, line);
        int k = stringToInteger(line);
        getline(cin, line);
        int t = stringToInteger(line);
        
        bool ret = Solution().containsNearbyAlmostDuplicate(nums, k, t);

        string out = boolToString(ret);
        cout << out << endl;
    }
    return 0;
}