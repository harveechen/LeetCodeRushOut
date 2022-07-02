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

bool cmp(pair<int, int> &lh, pair<int, int> &rh) {
    return lh.second < rh.second;
}

int main()
{
    int N;
    int A, B;
    scanf("%d", &N);
    vector<int> arr_A(N);
    vector<int> arr_B(N);
    int total = 0;
    for (int i = 0; i < N; i++) {
        scanf("%d %d", &A, &B);
        arr_A[i] = A;
        arr_B[i] = B;
        total += B;
    }

    vector<pair<int, int>> arr_val(N);
    for (int i = 0; i < N; i++) {
        int val = arr_A[i];
        for (int j = 0; j < N; j++) {
            if (i == j) {
                continue;
            }
            if (arr_A[j] > arr_B[i]) {
                val = max(arr_A[j] - arr_B[i], val);
            }
        }

        arr_val[i] = {i, val};
    }
    sort(arr_val.begin(), arr_val.end(), cmp);
    auto elem = arr_val[0];
    // total -= arr_B[elem.first];
    total += elem.second;

    printf("%d\n", total);
}