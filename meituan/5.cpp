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

using QueueMin = priority_queue<int, vector<int>, less<int>>;
using QueueMax = priority_queue<int, vector<int>, greater<int>>;
using Triple = tuple<int, QueueMin, QueueMax>;

void add(int x, QueueMin &que_min, QueueMax &que_max) {
    if (que_min.empty() || x < que_min.top()) {
        que_min.push(x);
        if (que_max.size() + 1 < que_min.size()) {
            que_max.push(que_min.top());
            que_min.pop();
        }
    } else {
        que_max.push(x);
        if (que_max.size() > que_min.size()) {
            que_min.push(que_max.top());
            que_max.pop();
        } 
    }
}

int find_median(QueueMin &que_min, QueueMax &que_max) {
    if (que_min.size() > que_max.size()) {
        return que_min.top();
    }
    return (que_max.top() + que_min.top()) / 2.0;
}

long long solution(vector<int> &arr) {
    int n = arr.size();
    vector<vector<Triple>> dp(n, vector<Triple>(n));

    long long ret = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            if ((j-i + 1) % 2 != 1) continue;
            
            dp[i][j] = Triple();
            QueueMin que_min;
            QueueMax que_max;

            ret += find_median(que_min, que_max);
        }
    }

    return ret;
}


int main()
{
    int n;
    cin >> n;
    int x;
    vector<int> arr;
    for (; n > 0; n--) {
        cin >> x;
        arr.push_back(x);
    }
    cout << solution(arr) << endl;
    return 0;
}