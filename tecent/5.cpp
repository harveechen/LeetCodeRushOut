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



int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    vector<int> b(m);
    int x;
    for (int k = 0; k < n; k++) {
        cin >> x;
        a[k] = x;
    }

    for (int k = 0; k < m; k++) {
        cin >> x;
        b[k] = x;
    }

    vector<vector<int>> interval;
    cin >> x;
    int l, r;
    for (int k = 0; k < x; k++) {
        cin >> l >> r;
        interval.push_back({l, r});
    }
    
    vector<int> cnt_a(x);
    vector<int> cnt_b(x);
    for (auto tmp : a) {
        for (int k = 0; k < x; k++) {
            if (tmp >= interval[k][0] && tmp <= interval[k][1]) {
                cnt_a[k]++;
            }
        }
    }

    for (auto tmp : b) {
        for (int k = 0; k < x; k++) {
            if (tmp >= interval[k][0] && tmp <= interval[k][1]) {
                cnt_b[k]++;
            }
        }
    }
    int cnt_le = 0, cnt_eq = 0, cnt_ge = 0;

    for (int k = 0; k < x; k++) {
        if (cnt_a[k] == cnt_b[k]) {
            cnt_eq++;
        } else if (cnt_a[k] < cnt_b[k]) {
            cnt_le++;
        } else {
            cnt_ge++;
        }
    }

    cout << cnt_ge << " " << cnt_eq << " " << cnt_le << endl;
 
    return 0;
}