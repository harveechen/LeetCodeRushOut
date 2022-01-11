#include <unordered_map>
#include <stack>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <extra/utils.hpp>

using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> stk;
        vector<int> res(temperatures.size());
        for (int i = 0; i < temperatures.size(); i++) {
            int temp = temperatures[i];
            if (stk.empty() || temperatures[stk.top()] >= temp) {
                stk.push(i);
            } else {
                while (!stk.empty() && temperatures[stk.top()] < temp) {
                    auto idx = stk.top();
                    stk.pop();
                    res[idx] = i-idx;
                }
                stk.push(i);
            }
        }
        while (!stk.empty() ) {
            auto idx = stk.top();
            stk.pop();
            res[idx] = 0;
        }
        return res;
    }
};

int main()
{
    string line;
    while (getline(cin, line))
    {
        vector<int> temperatures = stringToIntegerVector(line);
        
        vector<int> ret = Solution().dailyTemperatures(temperatures);

        string out = integerVectorToString(ret);
        cout << out << endl;
    }
    return 0;
}