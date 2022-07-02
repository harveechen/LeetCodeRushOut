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
    int T;
    scanf("%d", &T);
    int N;
    string tmp;
    
    int flag;
    for (; T > 0; T--) {
        unordered_set<string> _set;
        scanf("%d", &N);
        flag = 0;
        for (; N > 0; N--) {
            cin >> tmp;
            if (flag == 1) continue;
            if (tmp.size() == 1) {
                flag = 1;
                continue;
            } else if (tmp.size() == 2) {
                if (tmp[0] == tmp[1]) {
                    flag = 1;
                    continue;
                }
                string re_tmp(tmp);
                reverse(re_tmp.begin(), re_tmp.end());
                if (_set.count(re_tmp)) {
                    flag = 1;
                    continue;
                }
                _set.insert(tmp);
            } else {
                if (tmp[0] == tmp[2]) {
                    flag = 1;
                    continue;
                }
                string re_tmp(tmp);
                reverse(re_tmp.begin(), re_tmp.end());
                if (_set.count(re_tmp)) {
                    flag = 1;
                    continue;
                }
                _set.insert(tmp);
                _set.insert(tmp.substr(0, 2));
            }
        }
        if (flag == 1) cout << "YES" << endl;
        else cout << "NO" << endl;
        
    }
    
    return 0;
}