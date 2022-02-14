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
#include <string.h>
#include <extra/utils.hpp>

using namespace std;

class Solution {
public:
    typedef pair<int, int> Point;
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        bool check[m][n];

        memset(check, false, sizeof(check));
        Point directions[4]{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        int max_area = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int area = 0;
                if (!check[i][j] && grid[i][j]) {
                    queue<Point> Q;
                    Q.push(make_pair(i, j));

                    while (!Q.empty()) {
                        Point curr = Q.front();
                        Q.pop();
                        area++;
                        int i_curr = curr.first;
                        int j_curr = curr.second;
                        check[i_curr][j_curr] = true;
                        for (auto dir : directions) {
                            int i_next = i_curr + dir.first;
                            int j_next = j_curr + dir.second;

                            if (i_next >= 0 && i_next <= m-1 && j_next >= 0 && j_next <= n-1 && !check[i_next][j_next] && grid[i_next][j_next] == 1) {
                                Q.push(make_pair(i_next, j_next));  
                            }
                        }
                    }
                }
                max_area = max(max_area, area);
            }
        }

        return max_area;
    }
};

int main()
{
    vector<vector<int>> input{
        {0,0,1,0,0,0,0,1,0,0,0,0,0},
        {0,0,0,0,0,0,0,1,1,1,0,0,0},
        {0,1,1,0,1,0,0,0,0,0,0,0,0},
        {0,1,0,0,1,1,0,0,1,0,1,0,0},
        {0,1,0,0,1,1,0,0,1,1,1,0,0},
        {0,0,0,0,0,0,0,0,0,0,1,0,0},
        {0,0,0,0,0,0,0,1,1,1,0,0,0},
        {0,0,0,0,0,0,0,1,1,0,0,0,0}};


    cout << Solution().maxAreaOfIsland(input) << endl;
    return 0;
}