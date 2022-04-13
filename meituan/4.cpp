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

priority_queue<int, vector<int>, less<int>> que_min;
priority_queue<int, vector<int>, greater<int>> que_max;

void add(int x) {
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

double find_median() {
    if (que_min.size() > que_max.size()) {
        return que_min.top();
    }
    return (que_max.top() + que_min.top()) / 2.0;
}

int main()
{
    int n;
    cin >> n;
    int x;
    for (; n > 0; n--) {
        cin >> x;
        add(x);
    }

    cout << find_median() << endl;
 }