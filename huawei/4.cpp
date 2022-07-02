// 1 0 网格 1 的联通数

// 1 0 0
// 0 1 0


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

using namespace std;


int main()
{
    vector<vector<int>> graph = {
        {1, 0, 0},
        {0, 1, 1},
        {1, 0, 1}
    }; // input
    int n = graph.size();
    int m = graph[0].size();

    vector<vector<int>> vis(n, vector<int>(m));
    vector<vector<int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!graph[i][j] || vis[i][j]) continue;
            cnt++;
            queue<pair<int, int>> que;
            que.emplace(i, j);

            while (!que.empty()) {
                auto pos = que.front();
                que.pop();
                int i_curr = pos.first;
                int j_curr = pos.second;

                for (auto dir : dirs) {
                    int i_next = dir[0] + i_curr;
                    int j_next = dir[1] + j_curr;

                    if (i_next >= 0 && i_next < n &&
                        j_next >= 0 && j_next < m &&
                        !vis[i_next][j_next] && graph[i_next][j_next]) {
                            vis[i_next][j_next] = 1;
                            que.emplace(i_next, j_next);
                        }
                }
            }
        }
    }

    cout << cnt << endl;

    return 0;
}