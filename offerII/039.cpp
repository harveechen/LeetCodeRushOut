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
    int largestRectangleArea(vector<int>& heights) {
        stack<int> stk; // pos
        stk.push(-1);
        int maxArea = 0;
        for (int i = 0; i < heights.size(); i++)
        {
            while (stk.size() > 1 && heights[stk.top()] > heights[i])
            {
                int h = heights[stk.top()];
                stk.pop();
                maxArea = max(maxArea,  h * (i - stk.top() - 1));
            }
            stk.push(i);
        }
        int size = heights.size();
        while (stk.size() > 1)
        {
            int h = heights[stk.top()];
            stk.pop();
            maxArea = max(maxArea, h * (size - stk.top() - 1));
        }
        return maxArea;
    }
};

int main()
{
    string line;
    while (getline(cin, line))
    {
        vector<int> heights = stringToIntegerVector(line);
        
        int ret = Solution().largestRectangleArea(heights);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}