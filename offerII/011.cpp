#include <unordered_map>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>
#include "extra/utils.hpp"

using namespace std;

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        if (nums.size() < 2) return 0;
        unordered_map<int, int> pre_sum; // j+1 -> i = pm[i] - pm[j]; 这里key value 翻转
        int cnt = 0;
        pre_sum[cnt] = -1;
        int maxlen = 0;
        for (int i = 0; i < nums.size(); i++) {
            // 先计算当前计数（1多出的数量）
            cnt += nums[i] == 1 ? 1 : -1;
            if (pre_sum.find(cnt) != pre_sum.end()) {
                maxlen = max(maxlen, i - pre_sum[cnt]);
            } else {
                pre_sum[cnt] = i;
            }
        }
        return maxlen;
    }
};

int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> nums = stringToIntegerVector(line);
        
        int ret = Solution().findMaxLength(nums);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}