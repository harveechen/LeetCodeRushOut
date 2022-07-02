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
#include <math.h>

using namespace std;

inline long double poww(long double x, long double y) {
    if (x < 0) {
        return -pow(-x, y);
    } else {
        return pow(x, y);
    }
}

inline double f(double a, double b, double c, double x) {
    double x_2 = x * x;
    return x * x_2 + a * x_2 + b * x - c;
}

int main()
{
    int q;
    cin >> q;
    int a, b, c;

    for (int k = 0; k < q; k++) {
        cin >> a >> b >> c;
        int flag = 4 * a * a - 12 * b;
        int ret;
        if (flag >= 0) {
            double tmp = 2 * a;
            double x1 = (- tmp - sqrt(flag))/6.0;
            if (x1 > 0)
        }
        printf("%.8Lf\n",ret);
    }
}