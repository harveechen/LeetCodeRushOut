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
    bool isBipartite(vector<vector<int>>& graph) {
        int m = graph.size();
        
        int color[m];
        memset(color, -1, sizeof(m));

        for (int i = 0; i < m; i++) {
            if (color[i] == -1) {
                queue<int> Q;
                Q.push(i);
                color[i] = 0;

                while (!Q.empty()) {
                    int u = Q.front();
                    Q.pop();

                    for (auto const &v : graph[u]) {
                        if (color[v] == -1) {
                            Q.push(v);
                            color[v] = (color[u] + 1) % 2;
                        } else if (color[v] == color[u]) {
                            return false;
                        }
                    }
                }
            }
        }

        return true;
    }
};

int main()
{
    vector<vector<int>> input{{1,3},{0,2},{1,3},{0,2}};
    Solution().isBipartite(input);
    return 0;
}