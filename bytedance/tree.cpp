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


vector<int> solution(int n, vector<pair<int, int>> ops) {
    vector<int> residual(n+2);
    for (auto op : ops) {
        residual[op.first] += 1;
        residual[op.second+1] -= 1;
    }
    
    for (int i = 1; i <= n; i++) {
        residual[i] += residual[i-1];
    }

    return residual;
}


int main()
{
    int n, q;
    cin >> n >> q;
    int lh, rh;
    vector<pair<int, int>> ops;
    for (; q > 0; q--) {
        cin >> lh >> rh;
        ops.emplace_back(lh, rh);
    }
    auto cnt = solution(n, ops);
}
