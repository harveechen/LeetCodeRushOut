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
    int find_pike(vector<int> nums) {
        int n = nums.size();
        if (n < 3) perror("illegal");
        if (n == 3) return nums[1];
        int i = 0, j =  - 1;

        int mid = (i+j) / 2;

        while (i <= j) {
            if (nums[mid] > nums[mid-1] && nums[mid] < nums[mid+1]) 
                break;
            else if (nums[mid-1] > nums[mid] && nums[mid] > nums[mid+1]) {
                j = mid - 1;
            } else if (nums[mid-1] < nums[mid] && nums[mid] < nums[mid+1]) {
                i = mid + 1;
            } else if (nums[mid-1] > nums[mid] && nums[mid] < nums[mid+1]) {
                i = mid + 1;
            }
        }

        return mid;
    }
};

int main()
{
    string line;
    while (getline(cin, line))
    {
        vector<
    }
    return 0;
}