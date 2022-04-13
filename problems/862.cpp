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
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        int prefixSum[n+1];
        prefixSum[0] = 0;

        int queue[n+1];
        int head = 0, tail = 0;
        queue[tail] = 0;
        int min_len = n + 1;
        for (int i = 1; i <= n; i++) {
            prefixSum[i] = prefixSum[i-1] + nums[i-1];
            while (head <= tail && prefixSum[queue[tail]] >= prefixSum[i]) tail--;
            queue[++tail] = i;
            while (head <= tail && prefixSum[queue[head]] + k <= prefixSum[i]) {
                min_len = min(min_len, i-queue[head]);
                head++;
            }
        }

        return min_len > n ? -1 : min_len;
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
        cout << Solution().shortestSubarray(nums, k) << endl;
    }
    return 0;
}