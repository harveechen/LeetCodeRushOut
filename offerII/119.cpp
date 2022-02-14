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
    int longestConsecutive(vector<int>& nums) {
        // deduplication
        unordered_set<int> pool(nums.begin(), nums.end());
        int longest = 1;
        for (auto &num : pool) {
            if (pool.count(num-1) != 0) continue;
            int curr = 1;
            while (pool.count(num+curr)) {
                curr++;
            }
            longest = max(longest, curr);
        }
        return longest;
    }
};

int main()
{
    string line;
    while (getline(cin, line))
    {
        
    }
    return 0;
}