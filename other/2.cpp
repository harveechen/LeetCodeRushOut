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
    int N;
    scanf("%d", &N);
    vector<int> arr(N-1);
    int x;
    int pre;
    for (int i = 0; i < N; i++) {
        scanf("%d", &x);
        if (i > 0) {
            arr[i-1] = abs(pre - x);
        }
        pre = x;
    }
    unordered_map<int, int> _map;
    int min_val = 1000001;
    int max_val = -1;
    int max_same = 1;
    for (auto elem : arr) {
        _map[elem]++;
        if (elem < min_val) min_val = elem;
        if (elem > max_val) max_val = elem;
        if (_map[elem] > 1) {
            max_same = max(max_same, _map[elem]);
        }
    }
    int cnt = 0;
    for (int i = min_val; i <= max_val; i++) {
        if (_map.count(i) == 0) cnt++;
    }

    if (cnt > 0 || max_same > 1) {
        printf("NO\n");
        printf("%d %d\n", max_same, cnt);
    } else {
        printf("YES\n");
        printf("%d %d\n", min_val, max_val);
    }

    return 0;
}