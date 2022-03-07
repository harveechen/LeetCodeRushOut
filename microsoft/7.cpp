// N
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

int main()
{
    int N, M;
    cin >> N >> M;
    vector<vector<int>> graph(N, vector<int>());
    vector<int> inorder(N);
    queue<int> _queue;
    int target;
    int src;
    for (; M > 0; M--) {
        cin >> src >> target;
        graph[src].push_back(target);
        inorder[target]++;
    }

    for (int i = 0; i < N; i++) {
        if (inorder[i] == 0) _queue.push(i);
    }
    vector<int> ret;
    while (!_queue.empty()) {
        int tmp = _queue.front();
        _queue.pop();
        ret.push_back(tmp);
        for (int target : graph[tmp]) {
            inorder[target]--;
            if (inorder[target] == 0) _queue.push(target);
        }
    }

    // print ret;
    return 0;
}