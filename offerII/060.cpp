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
    typedef pair<int, int> ValOccur;
    static bool cmp(ValOccur &m, ValOccur &n) {
        return m.second > n.second;
    };

    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> occurs;
        for (auto &num : nums) {
            occurs[num]++;
        }


        priority_queue<ValOccur, vector<ValOccur>, decltype(&cmp)> Q(cmp);
        for (auto o : occurs) {
            int num, cnt;
            tie(num, cnt) = o;
            if (Q.size() == k) {
                if (Q.top().second < cnt) {
                    Q.pop();
                    Q.emplace(num, cnt);
                }
            } else {
                Q.emplace(num, cnt);
            }
        }

        vector<int> ret;
        while (!Q.empty()) {
            ret.emplace_back(Q.top().first);
            Q.pop();
        }
        sort(ret.begin(), ret.end(), [](int &a, int &b) {return a>b;});
        return ret;
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
        
        vector<int> ret = Solution().topKFrequent(nums, k);

        string out = integerVectorToString(ret);
        cout << out << endl;
    }
    return 0;
}