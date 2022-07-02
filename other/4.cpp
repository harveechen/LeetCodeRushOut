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

bool cmp(pair<int, int> lh, pair<int, int> rh) {
    return lh.second < rh.second;
}

int main()
{
    int N;
    scanf("%d", &N);
    unordered_map<int, vector<int>> tree_map;
    unordered_map<int, int> tree_cnt;
    // unordered_map<int, int> tree_number;
    int h, t;
    int h_max = -1;
    for (int i = 0; i < N; i++) {
        scanf("%d %d", &h, &t);
        tree_map[h].push_back(t);
        tree_cnt[h] += t;
        h_max = max(h_max, h);
    }

    if (tree_map[h_max].size() * 2 > N) {
        cout << 0 << endl;
    } else {
        vector<pair<int, int>> arr;
        for (auto elem : tree_cnt) {
            arr.emplace_back(elem.first, elem.second);
        }

        sort(arr.begin(), arr.end(), cmp);

        
    }
    return 0;
}