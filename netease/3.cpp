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

inline int get_div_num(int x, int div) {
    int ret = 0;
    for (; x % div == 0; x = x / div) ret++;

    return ret;
}

int solution(vector<int> &arr, vector<int> &flag, int n, int k) {
    vector<vector<int>> cnt2(n+1, vector<int>(2));
    vector<vector<int>> cnt5(n+1, vector<int>(2));
    for (int k = 1; k <= n; k++) {
        cnt2[k][flag[k]] = get_div_num(arr[k], 2);
        cnt5[k][flag[k]] = get_div_num(arr[k], 5);
    }
    int lh = 1, rh = -1;
    int r2 = 0, r5 = 0, b2 = 0, b5 = 0;
    int min_inv = INT_MAX;
    while (rh <= n) {
        if (min(r2, r5) + min(b2, b5) >= k) {
            min_inv = min(min_inv, rh - lh + 1);
            
            if (flag[lh] == 0) {
                r2 -= cnt2[lh][0];
                r5 -= cnt5[lh][0];
            } else {
                b2 -= cnt2[lh][1];
                b5 -= cnt5[lh][1];
            }
            lh++;
        } else {
            rh++;
            if (rh > n) break;
            if (flag[rh] == 0) {
                r2 += cnt2[rh][0];
                r5 += cnt5[rh][0];
            } else {
                b2 += cnt2[rh][1];
                b5 += cnt5[rh][1];
            }
        }
    }
    return min_inv != INT_MAX ? min_inv : -1;
}

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> arr(n+1);
    int x;
    for (int k = 1; k <= n; k++) {
        cin >> x;
        arr[k] = x;
    }
    string str;
    cin >> str;
    vector<int> flag(n+1);
    for (int k = 1; k <= n; k++) {
        if (str[k-1] == 'R') flag[k] = 0;
        else flag[k] = 1;
    }

    cout << solution(arr, flag, n, k) << endl;
    return 0;
}