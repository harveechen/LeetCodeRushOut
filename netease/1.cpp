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
    vector<int> arr(n+1);
    vector<int> flag(n+1);
    int x;
    for (int k = 1; k <= n; k++) {
        cin >> x;
        arr[k] = x;
    }
    string str;
    cin >> str;
    for (int k = 1; k <= str.size(); k++) {
        if (str[k-1] == 'R') flag[k] = 0;
        else flag[k] = 1;
    }

    int ans[n+1][2];
    ans[0][0] = 0;
    ans[0][1] = 0;
    for (int k = 1; k <= n; k++) {
        if (flag[k] == 0) {
            ans[k][0] = ans[k-1][0] + arr[k];
            ans[k][1] = ans[k-1][1];
        } else {
            ans[k][1] = ans[k-1][1] + arr[k];
            ans[k][0] = ans[k-1][0];
        }
    }

    int q;
    cin >> q;
    for (; q > 0; q--) {
        cin >> x;

        int epoch = x / n;
        int num = x % n;

        long long r_cnt = epoch * ans[n][0] + ans[num][0];
        long long p_cnt = epoch * ans[n][1] + ans[num][1];

        cout << r_cnt << " " << p_cnt << endl;
    }

    return 0;
}