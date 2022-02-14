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
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        int parent[n+1];
        for (int i = 1; i <= n; i++) {
            parent[i] = i;
        }

        for (auto &e : edges) {
            if (_find(parent, e[0]) ==  _find(parent, e[1])) {
                return e;
            }   
            _union(parent, e[0], e[1]);
        }

        return {};
    }

    void _union(int* parent, int left, int right) {
        parent[_find(parent, left)] = _find(parent, right);
    }

    int _find(int* parent, int index) {
        if (parent[index] != index) {
            parent[index] = _find(parent, parent[index]);
        }
        return parent[index];
    }
};

int main()
{
    vector<vector<int>> input{{1,2},{1,3},{2,3}};
    Solution().findRedundantConnection(input);
    return 0;
}