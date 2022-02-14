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
    string alienOrder(vector<string>& words) {
        char startChar = 'a';
        vector<vector<int>> graph(26, vector<int>(26));
        vector<int> indegree(26);
        vector<bool> seen(26);
        int cnt = 0;
        for (auto &item : words) {
            for (int k = 0; k < item.size(); k++) {
                seen[item[k]-startChar] = true;
                if (k >= 1) {
                    if (graph[item[k-1]-startChar][item[k]-startChar] == 0) {
                        graph[item[k-1]-startChar][item[k]-startChar] = 1;
                        indegree[item[k]-startChar]++;
                        cnt++;
                    }
                }
            }
        }
        queue<int> _queue;
        string ret;
        for (int k = 0; k < 26; k++) {
            if (seen[k] && indegree[k] == 0) {
                _queue.push(k);
                ret += 'a' + k;
            }
        }

        while (!_queue.empty()) {
            int k = _queue.front();
            _queue.pop();

            for (int i = 0; i < 26 && seen[i] &&graph[k][i]; i++) {
                --cnt;
                if (--indegree[i] == 0) {
                    _queue.push(i);
                    ret += 'a' + i;
                }
            }
        }
        cout << cnt << endl;
        // if (cnt != 0) return "";
        return ret;
    }
};

int main()
{
    vector<string> input{"wrt","wrf","er","ett","rftt"};
    Solution().alienOrder(input);
    return 0;
}