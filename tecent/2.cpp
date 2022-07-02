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
    int n, m;
    cin >> n >> m;
    float p;
    for (int k = 0; k < m; k++) {
        cin >> p;
        float tmp = n / (1-p);
        n = (int)tmp;
        if (tmp - (float)n < 0.000001) {
            n -= 1;
        }
    }

    cout << n << endl;
    return 0;
}