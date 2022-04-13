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

long long solution(long long a, long long  b, long long x, long long y) {
    long long min_gift = min(a, b);
    long long min_req = min(x, y);
    long long min_upper = min_gift / min_req;

    long long ret = 0;
    long long i, j;
    for (i = min_upper; i >= 0; i--) {
        j = min((a-i*x)/y, (b-i*y)/x);
        for (; j >= 0; j--) {
            if (i * x + j * y <= a && i * y + j * x <= b) {
                ret = max(ret, i + j);
                break;
            }
        }
    }

    return ret;
}


int main()
{
    int a, b, x, y;
    cin >> a >> b >> x >> y;

    cout << solution(a, b, x, y) << endl;
}