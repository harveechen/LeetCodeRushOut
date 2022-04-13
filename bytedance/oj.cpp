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
    vector<int> stk;
    int ret = 0;
    for (int i = 0; i < arr.size(); i++) {
        if (i == 0) {
            ret += arr[i];
            stk.push_back(i);
            continue;
        }
        if (arr[i] != -1) {
            while (!stk.empty() && arr[stk.back()] >= arr[i]) stk.pop_back();
        }
        
        stk.push_back(i);
        ret += arr[stk.front()];
    }

    return ret;
}

int main()
{
    int M, N;
    cin >> M >> N;
    vector<int> arr(M, -1);
    int day , money;
    for (; N > 0; N--) {
        cin >> day >> money;
        arr[day] = money;
    }

    cout << solution(arr) << endl;
    return 0;
}