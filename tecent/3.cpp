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
    int c;
    cin >> c;

    vector<double> f(c);
    double x;
    for (int k = 0; k < c; k++) {
        cin >> x;
        f[k] = x;
    }

    
    double tmp;
    double max_tmp;
    int idx = 0;
    for (int k = 0; k < c; k++) {
        tmp = 0;
        for (int s = 0; s < c; s++) {
            cin >> x;
            tmp += x * f[s];
        }

        if (k == 0) {
            max_tmp = tmp;
            continue;
        }

        if (max_tmp < tmp) {
            max_tmp = tmp;
            idx = k;
        }
    }

    cout << idx << endl;

    return 0;
}