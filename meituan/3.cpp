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
    int n;
    cin >> n;
    // vector<int> arr;
    int ret = 0;
    int flag = 0;
    int min_val = INT_MAX;
    unordered_map<int, vector<int>> _map;
    int a;
    for (; n > 0; n--) {
        cin >> a;
        if (a >= 0) {
            ret += a;
            flag += a % 7;
            flag = flag % 7;
            min_val = min(a, min_val);
        }
        else {
            _map[7-((-a)%7)].push_back(a);
        }  
    }

    for (int k = 0; k < 7; k++) {
        sort(_map[k].begin(), _map[k].end());
    }
    
    if (flag == 0) cout << ret << endl;
    else {
        if (!_map[7-flag].empty()) {
            int tmp = _map[7-flag].front();
            ret += tmp;
            cout << ret << endl;
        }
    }
    cout << 0 << endl;
    return 0;
}