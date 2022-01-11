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
    int maximalRectangle(vector<string>& matrix) {
        int m = matrix.size();
        if (m <= 0) return 0;
        int n = matrix[0].size();
        vector<int> heights(n, 0);
        int maxArea = 0;
        stack<int> stk;
        stk.push(-1);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == '1')
                    heights[j]++;
                else
                    heights[j] = 0;
                while (stk.size() > 1 && heights[stk.top()] > heights[j]) {
                    int h = heights[stk.top()];
                    stk.pop();
                    maxArea = max(maxArea, h * (j - stk.top() - 1));
                }
                stk.push(j);
            }

            while (stk.size() > 1) {
                int h = heights[stk.top()];
                stk.pop();
                 maxArea = max(maxArea, h * (n - stk.top() - 1));
            }
        }

        return maxArea;
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