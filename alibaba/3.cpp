#include <iostream>
#include <vector>

using namespace std;

static const long long MAX_NUM = 1000000007;

int n; // total
int k; // first day
long long cnt = 0;

// flag = 0: prev_prev < prev, curr > prev

void trace(int rest, int prev, int flag, vector<vector<long long>> &dp_0,
           vector<vector<long long>> &dp_1) {
    if (rest == 0) {
        cnt++;
        if (cnt > MAX_NUM) {
            cnt = cnt % MAX_NUM;
        }
    }
    if (flag == 0) {
        flag = 1;
        for (int i = prev + 1; i <= rest; i++) {
            if (dp_0[rest][i]) {
                cnt += dp_0[rest][i];
                if (cnt > MAX_NUM) {
                    cnt = cnt % MAX_NUM;
                }
                return;
            }
            trace(rest - i, i, flag, dp_0, dp_1);
        }
    } else {
        flag = 0;
        for (int i = 1; i < prev; i++) {
            if (dp_0[rest][i]) {
                cnt += dp_0[rest][i];
                if (cnt > MAX_NUM) {
                    cnt = cnt % MAX_NUM;
                }
                return;
            }
            trace(rest - i, i, flag, dp_0, dp_1);
        }
    }
}

int main() {
    cin >> n >> k;
    if (n == k)
        return 1;
    vector<vector<long long>> dp_0(n + 1, vector<long long>(k + 1));
    vector<vector<long long>> dp_1(n + 1, vector<long long>(k + 1));
    trace(n - k, k, 0, dp_0, dp_1);
    trace(n - k, k, 1, dp_0, dp_1);
    cout << cnt << endl;
}