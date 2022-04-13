#include <algorithm>
#include <iostream>
#include <limits.h>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    if (M >= N)
        cout << -1 << endl;
    vector<vector<int>> graph(N);
    int T, x;
    for (int i = 0; i < N; i++) {
        scanf("%d", &T);
        for (; T > 0; T--) {
            scanf(",%d", &x);
            if (x == i) {
                cout << -1 << endl;
                return 0;
            }
            graph[i].push_back(x);
        }
    }
    if (graph[M].size() == 0) {
        cout << "null" << endl;
        return 0;
    }
    vector<int> vis(N);
    queue<int> _queue;
    _queue.push(M);
    vector<vector<int>> ret;
    while (!_queue.empty()) {
        int n = _queue.size();
        vector<int> tmp;
        for (int i = 0; i < n; i++) {
            int id = _queue.front();
            _queue.pop();
            vis[id] = 1;
            tmp.push_back(id);
            for (auto &item : graph[id]) {
                if (vis[item] == 1) {
                    cout << -1 << endl;
                    return 0;
                }
                _queue.push(item);
            }
        }
        ret.push_back(tmp);
    }
    // std::sort(ret.begin(), ret.end());
    int n = ret.size();
    string out;
    for (int i = n - 1; i > 0; i--) {
        std::sort(ret[i].begin(), ret[i].end());
        for (int j = 0; j < ret[i].size(); j++) {
            out += to_string(ret[i][j]);
            out +=",";
        }
    }
    out.erase(out.end()-1);
    cout << out << endl;
    return 0;
}