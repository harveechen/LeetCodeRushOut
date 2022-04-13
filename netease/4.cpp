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

using Pos = pair<int, int>;

vector<vector<int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

struct hash_pair {
    template <typename T1, typename T2>
    size_t operator()(const pair<T1, T2> &p) const {
        return std::hash<T1>()(p.first) ^ std::hash<T2>()(p.second);
    }
};

template <typename T> using ChessMap = unordered_map<T, T, hash_pair>;

template <typename T> T _find(T x, ChessMap<T> &parent) {
    while (x != parent[x]) {
        x = parent[x];
    }
    return x;
}

template <typename T> bool _merge(T x, T y, ChessMap<T> &parent) {
    T parent_x = _find<T>(x, parent);
    T parent_y = _find<T>(y, parent);
    if (parent_x == parent_y)
        return false;

    parent[parent_x] = parent_y;
    return true;
}

int main() {
    int n, m, x;
    cin >> n >> m;
    vector<vector<int>> graph(n, vector<int>(m));
    ChessMap<Pos> parent;
    unordered_map<int, vector<Pos>> _map;
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            cin >> x;
            _map[x].emplace_back(i, j);
            auto pos = make_pair(i, j);
            parent[pos] = pos;
        }
    }
    int q;
    cin >> q;
    int ret = 0;
    for (; q > 0; q--) {
        cin >> x;
        if (_map.count(x)) {
            for (auto &pos : _map[x]) {
                graph[pos.first][pos.second] = 1;
                ret++;
            }

            for (auto &pos : _map[x]) {
                int i = pos.first;
                int j = pos.second;

                for (auto dir : dirs) {
                    int next_i = i + dir[0];
                    int next_j = j + dir[1];

                    if (next_i >= 0 && next_i < n && next_i >= 0 &&
                        next_j < m && graph[next_i][next_j] == 1) {
                        auto next_pos = Pos(next_i, next_j);
                        if (_merge(pos, next_pos, parent)) {
                            ret--;
                        }
                    }
                }
            }
        }
        cout << ret << endl;
    }
}