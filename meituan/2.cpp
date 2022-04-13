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

int solution(vector<int> &arr) {
    int m = arr.front();
    int t = arr.back();

    int ret = INT_MAX;
    for (auto pos : arr) {
        ret = min(ret, abs((pos-m) - (t-pos)));
    }

    return ret;
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr;
    int pos;
    for (int k = n; k > 0; k--) {
        cin >> pos;
        arr.push_back(pos);
    }

    cout << solution(arr) << endl;
}