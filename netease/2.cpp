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


int main()
{
    int x_a, y_a, x_b, y_b, x_c, y_c;
    cin >> x_a >> y_a >> x_b >> y_b >> x_c >> y_c;
    int v1, d1, v2, d2;
    cin >> v1 >> d1;
    cin >> v2 >> d2;
    if (d1 == d2 && v1 == v2) {
        cout << -1 << endl;
        return 0;
    }

    double ac = sqrt((x_a - x_c) * (x_a - x_c) + (y_a - y_c) * (y_a - y_c));
    double ab = sqrt((x_a - x_b) * (x_a - x_b) + (y_a - y_b) * (y_a - y_b));
    double bc = sqrt((x_b - x_c) * (x_b - x_c) + (y_b - y_c) * (y_b - y_c));

    if (d1 != d2) {
        if (d1 == 0) {
            cout << ab / (double)(v1 + v2) << endl;
        } else {
            cout << (ac+bc) / (double)(v1 + v2) << endl;
        }
    } else {
        if (d1 == 0) {
            if (v1 > v2)
                cout << ab / (double)(v1 - v2) << endl;
            else
                cout << (ac + bc) / (double)(v2 - v1) << endl;
        } else {
            if (v1 > v2)
                cout << (ac + bc) / (double)(v1 - v2) << endl;
            else
                cout << ab / (double)(v2 - v1) << endl;
        }
    }
}