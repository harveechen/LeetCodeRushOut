#include <algorithm>
#include <extra/utils.hpp>
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

stack<pair<int, int>> stk;
vector<pair<int, int>> empty;
int minVal = INT_MAX;
void trace(vector<vector<int>> &A, int cnt);

int solution(vector<vector<int>> &A) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (A[i][j] > 1) {
                stk.emplace(i, j);
            } else if (A[i][j] == 0) {
                empty.emplace_back(i, j);
            }
        }
    }

    if (stk.size() == 0)
        return 0;

    int idx = 0;
    trace(A, 0);
    return minVal;
}

void trace(vector<vector<int>> &A, int cnt) {
    // target
    if (stk.size() == 0) {
        minVal = min(minVal, cnt);
        return;
    };
    auto src = stk.top();

    for (auto &target : empty) {
        if (A[target.first][target.second] == 0) {
            // try 
            A[target.first][target.second] = 1;
            A[src.first][src.second]--;
            if (A[src.first][src.second] == 1) {
                stk.pop();
            }

            int dis = abs(src.first - target.first) + abs(src.second - target.second);
            trace(A, cnt + dis);

            // resume
            if (A[src.first][src.second] == 1) {
                stk.push(src);
            }
            A[target.first][target.second] = 0;
            A[src.first][src.second]++;
        }
    }
}

int main() {
    vector<vector<int>> input{{0, 6, 0}, {2, 0, 0}, {0, 1, 0}};
    // vector<vector<int>> input{{1, 3, 1}, {1, 1, 0}, {1, 1, 0}};
    cout << solution(input) << endl;
    return 0;
}