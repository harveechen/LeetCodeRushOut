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
    vector<int> parent;
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        parent.resize(n);
        for (int k = 0; k < n; k++) parent[k] = k;

        for (int j = 1; j < n; j++) {
            for (int i = 0; i < j; i++) {
                if (isConnected[i][j]) {
                    _union(i, j);
                }
            }
        }
        
        int cnt = 0;
        for (int k = 0; k < n; k++) {
            if (parent[k] == k) cnt++;
        }

        return cnt;
    }

    int _find(int index) {
        if (parent[index] != index) {
            parent[index] = _find(parent[index]);
        }
        return parent[index];
    }

    void _union(int lh, int rh) {
        parent[_find(lh)] = _find(rh);
    }

    // 1 0 0 1
    // 0 1 1 0
    // 0 1 1 1
    // 1 0 1 1
};

int main()
{
    vector<vector<int>> input{{1,1,1}, {1,1,1},{1,1,1}};
    Solution().findCircleNum(input);
    return 0;
}