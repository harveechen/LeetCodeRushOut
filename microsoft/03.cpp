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

class Solution
{
public:
    int solution(string &S, vector<int> &A)
    {
        // write your code in C++14 (g++ 6.2.0)
        int n = S.size();
        if (n == 1) return 1;
        vector<vector<int>> graph(n);

        // build tree;
        for (int k = 1; k < n; k++) {
            graph[A[k]].push_back(k);
        }
        int maxVal = INT_MIN;
        dfs(graph, S, 0, maxVal);
        return maxVal;
    }

    int dfs(vector<vector<int>> &graph, string &S, int root, int &maxVal) {
        if (graph[root].size() == 0) return 1;

        vector<int> tmp;
        for (auto &item : graph[root]) {
            int ret = dfs(graph, S, item, maxVal);
            if (S[root] != S[item])
                tmp.push_back(ret);
        }
        int ret = 1;

        if (tmp.size() == 1) {
            maxVal = max(maxVal, tmp[0] + 1);
            return tmp[0] + 1;
        }

        if (tmp.size() > 1) {
            sort(tmp.begin(), tmp.end(), greater<int>());
            maxVal = max(maxVal, tmp[0]+tmp[1]+1);
            return max(tmp[0], tmp[1]) + 1;
        }
        maxVal = max(maxVal, 1);
        return 1;
    }
};

int main()
{
    string a = "abab";
    vector<int> b{-1, 2, 0, 1};
    cout << Solution().solution(a,b) << endl;
    return 0;
}