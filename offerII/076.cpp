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
    int findKthLargest(vector<int>& nums, int k) {
        return quickSelect(nums, 0, nums.size()-1, k);
    }

    int quickSelect(vector<int>& arr, int lh, int rh, int k) {
        if (k > 0 && k <= rh - lh + 1) {
            int pos = random_partition(arr, lh, rh);

            if (pos - lh == k - 1) {
                return arr[pos];
            }

            if (pos - lh > k - 1) {
                return quickSelect(arr, lh, pos - 1, k);
            }

            return quickSelect(arr, pos + 1, rh, k - pos + lh - 1);
        }

        return INT_MAX;
    }

    int random_partition(vector<int> &arr, int lh, int rh) {
        int n = rh - lh + 1;
        int pivot = rand() % n;
        swap(arr[lh+pivot], arr[rh]);
        return partition(arr, lh, rh);
    }

    int partition(vector<int> &arr, int lh, int rh) {
        int x = arr[rh], idx = lh;

        for (int i = lh; i < rh; i++) {
            if (arr[i] >= x) {
                swap(arr[i], arr[idx]);
                idx++;
            }
        }

        swap(arr[idx], arr[rh]);
        return idx;
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
        
        int ret = Solution().findKthLargest(nums, k);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}