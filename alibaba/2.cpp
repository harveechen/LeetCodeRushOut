#include <iostream>
#include <vector>

using namespace std;

vector<int> vis;
vector<vector<int>> ret;
int cnt = 0;
int n, t;

void trace(int idx, vector<int> &tmp) {
    if (cnt >= t) return;
    if (idx == n) {
        cnt++;
        ret.push_back(tmp);
        return;
    }

    for (int i = 1; i <= n; i++) {
        if (idx + 1 == i || vis[i] == 1) continue;
        vis[i] = 1;
        tmp.push_back(i);
        trace(idx + 1, tmp);
        tmp.pop_back();
        vis[i] = 0;
    }
}

int main() {
    
    cin >> n >> t;
    vis.resize(n+1);
    vector<int> tmp;
    trace(0, tmp);
    for (int i = 0; i < ret.size(); i++) {
        int len = ret[i].size();
        for (int j = 0; j <  len - 1; j++) {
            cout << ret[i][j] << " ";
        }
        cout << ret[i][len-1] << endl;
    }
}