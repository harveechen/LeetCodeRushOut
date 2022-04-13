#include <algorithm>
#include <iostream>
#include <limits.h>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;
unordered_map<string, int> score;
unordered_map<string, int> name;
bool cmp(pair<string, int> &lh, pair<string, int> &rh) {
    if (lh.second > rh.second) {
        return true;
    } else if (lh.second == rh.second) {
        return name[lh.first] < name[rh.first];
    }
    return false;
}

int main() {
    int topN, M;
    // cin >> topN >> M;

    int cnt = 0;
    string line;
    string item;
    stringstream ss;
    std::getline(cin, line);
    ss.str(line);
    ss >> topN >> M;

    for (; M > 0; M--) {
        std::getline(cin, line);
        ss.clear();
        ss.str(line);
        while (std::getline(ss, item, ' ')) {
            score[item] += 3;
            if (name.count(item) == 0) {
                name[item] = cnt;
                cnt++;
            }
        }
        std::getline(cin, line);
        ss.clear();
        ss.str(line);
        while (std::getline(ss, item, ' ')) {
            score[item] += 1;
            if (name.count(item) == 0) {
                name[item] = cnt;
                cnt++;
            }
        }
    }
    vector<pair<string, int>> arr;
    for (auto &it : score) {
        arr.emplace_back(it.first, it.second);
    }

    std::sort(arr.begin(), arr.end(), cmp);
    for (int i = 0; i < topN; i++) {
        cout << arr[i].first << " ";
    }
    return 0;
}