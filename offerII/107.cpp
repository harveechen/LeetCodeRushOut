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
    typedef pair<int, int> Position;
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        queue<Position> Q;
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> dis(m, vector<int>(n));

        vector<Position> directions{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 0) {
                    Q.emplace(i, j);
                    dis[i][j] = 0;
                } else {
                    dis[i][j] = INT_MAX;
                }
            }
        }

        while (!Q.empty()) {
            auto &pos = Q.front();
            Q.pop();
            //
            int i = pos.first;
            int j = pos.second;
            for (auto &d : directions) {
                int i_next = i + d.first;
                int j_next = j + d.second;

                if (i >= 0 && i < m && j >= 0 && j < n && dis[i][j] + 1 < dis[i_next][j_next]) {
                    dis[i_next][j_next] = dis[i][j]  + 1;
                    Q.emplace(i_next, j_next);
                }
            }
        }
        return dis;
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