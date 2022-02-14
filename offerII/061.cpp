#include <unordered_map>
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
    typedef pair<int, int> IndexPair;
    typedef vector<int> ValuePair;
    struct CMP
    {
        CMP(vector<int> &n1, vector<int> &n2): nums1(move(n1)), nums2(move(n2)) {};
        bool operator() (IndexPair &lh, IndexPair &rh) {
            return nums1[lh.first] + nums2[lh.second] > nums1[rh.first] + nums2[rh.second];
        };
        vector<int> nums1, nums2;
        ValuePair get(IndexPair &idx) {
            return {nums1[idx.first], nums2[idx.second]};
        }

        bool hasNext(IndexPair &idx) {
            return idx.second + 1 < nums2.size();
        }
    };

    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int num1_size = min((int)nums1.size(), k);
        vector<IndexPair> tmp;
        for (int i = 0; i < num1_size; i++) {
             tmp.emplace_back(i, 0);
        }
        auto cmp = CMP(nums1, nums2);
        priority_queue<IndexPair, vector<IndexPair>, decltype(cmp)> Q(tmp.begin(), tmp.end(), cmp);

        vector<ValuePair> res;
        while (!(Q.empty() || res.size() == k) ) {
            auto tmp = Q.top();
            Q.pop();
            res.push_back(cmp.get(tmp));
            if (cmp.hasNext(tmp)) {
                Q.emplace(tmp.first, tmp.second+1);
            }
        }

        return res;
    }
};

int main()
{
    vector<int> b{1,2, 3};
    vector<int> a{1,1,2};
    Solution().kSmallestPairs(a, b, 10);
    return 0;
}