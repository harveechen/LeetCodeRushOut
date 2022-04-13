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

int solution(string &str) {
    vector<int> cnt(3);
    for (auto &ch : str) {
        if (ch >= 'a' && ch <= 'c')
            cnt[ch-'a']++;
    }

    int cnt_a = cnt[0] - 1;
    int cnt_b = cnt[1];
    int cnt_c = cnt[2] / 3;

    int ret = min({cnt_a, cnt_b, cnt_c});
    return ret;
}

int main()
{
    string line;
    getline(cin, line);

    cout << solution(line) << endl;
    return 0;
}