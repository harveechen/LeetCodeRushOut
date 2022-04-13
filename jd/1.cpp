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

int solution(string str, int n) {
    vector<vector<int>> arr(3);
    for (int i = 0; i < str.size(); i++) {
        arr[str[i]-'A'].push_back(i);
    }
    int flag_a = arr[0].size() < n ? 1 : 0;
    int flag_b = arr[1].size() < n ? 1 : 0;
    int flag_c = arr[2].size() < n ? 1 : 0;

    int flag = flag_a + flag_b + flag_c;
    if (flag == 0) return 0;
    else if (flag == 1) return 1;

    return 2;
}

int main()
{
    int T;
    int n;
    string line;
    cin >> T;
    for (; T > 0; T--) {
        cin >> n;
        cin >> line;
        cout << solution(line, n) << endl;
    }
    
    return 0;
}