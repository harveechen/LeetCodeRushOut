#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <extra/utils.hpp>

using namespace std;

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int start = 0, end = nums.size();
        if (end == 1) return nums[0];
        int mid = (start + end) / 2;

        while (true) {
            int off = (mid % 2 == 0) ? 1 : -1;
            if (nums[mid] != nums[mid+off]) { // start before mid
                if (mid == 0 || nums[mid] != nums[mid-off]) return nums[mid];
                end = mid;
            } else {
                start = mid+ (3+off)/2;
            }

            mid = (start + end) / 2;
        }
    }
};

int main()
{
    string line;
    while (getline(cin, line))
    {
        vector<int> nums = stringToIntegerVector(line);
        
        int ret = Solution().singleNonDuplicate(nums);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}