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
    bool sequenceReconstruction(vector<int>& org, vector<vector<int>>& seqs) {
        int n = org.size();
        if (n > 0 && seqs.size() == 0) return false;
        vector<vector<int>> graph(n+1);
        vector<int> indegree(n+1);
        vector<bool> seen(n+1);
        int cnt = 0;
        for (auto &item : seqs) {
            for (int k = 0; k < item.size(); k++) {
                if (item[k] < 1 || item[k] > n) return false;
                if (!seen[item[k]]) {
                    seen[item[k]] = true;
                    cnt++;
                }
                if (k >= 1) {
                    graph[item[k-1]].push_back(item[k]);
                    indegree[item[k]]++;
                }
            }
        }

        if (cnt != n) return false;

        queue<int> _queue;
        int idx = 0;
        for (int k = 1; k <= n; k++) {
            if (indegree[k] == 0) {
                _queue.push(k);
                if (org[idx++] != k) return false;
            }
        }

        if (_queue.size() > 1) return false;

        while (!_queue.empty()) {
            int k = _queue.front();
            _queue.pop();

            for (auto &item : graph[k]) {
                if (--indegree[item] == 0) {
                    _queue.push(item);
                    if (org[idx++] != item) return false;
                }
            }
            if (_queue.size() > 1) return false;
        }
        if (idx != n) return false;

        return true;
    }
};

int main()
{
    vector<int> org{1,2,3};
    vector<vector<int>> seqs{{1,2},{1,3},{2,3}};
    Solution().sequenceReconstruction(org, seqs);
    return 0;
}