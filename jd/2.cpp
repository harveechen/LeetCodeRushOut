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
#include <list>

using namespace std;

struct cmp
{
    bool operator()(vector<int> &lh, vector<int> &rh) {
        return lh.size() > rh.size();
    }
};


int solution(vector<int> &arr, int k) {
    if (k == 1) return arr.size();
    vector<vector<int>> arr_seq;

    for (auto &item : arr) {
        if (arr_seq.size() == 0) {
            arr_seq.push_back({item});
            continue;
        }
        
        for (auto &seq : arr_seq) {
            if (seq.back() < item) {
                seq.push_back(item);
            }
        }

        arr_seq.push_back({item});
    }

    sort(arr_seq.begin(), arr_seq.end(), cmp());
    int ret = 0;
    for (int i = 0; i < arr_seq.size(); i++) {
        if (arr_seq[i].size() >= k) ret++;
        else break;
    }
    return ret;
}

int main()
{
    int T;
    cin >> T;
    int n, k;
    int x;
    for (; T > 0; T--) {
        cin >> n >> k;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> x;
            arr[i] = x;
        }

        cout << solution(arr, k) << endl;
    }
    return 0;
}