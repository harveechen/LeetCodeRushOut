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
#include <sstream>

using namespace std;

long long solution(vector<int> &arr, int N) {
    vector<int> dd;
    long long ret = 0;
    for (int i = 0; i < arr.size(); i++) {
        while (!dd.empty() && arr[i] > arr[dd.back()]) {
            int top = dd.back();
            dd.pop_back();
            if (dd.empty()) break;
            int left = dd.back();
            int currW = i - left - 1;
            int currH = min(arr[left], arr[i]) - arr[top];
            ret += (currW / N) * currH;
        }
        
        dd.push_back(i);
    }

    return ret;
}

int main()
{
    int N, M;
    cin >> N >> M;
    vector<int> arr;
    int x;
    string line;
    cin >> line;
    stringstream ss(line);
    string item;
    while (std::getline(ss, item, ',')) {
        arr.push_back(min(stoi(item), 0));
    }

    cout << solution(arr, N) << endl;
    return 0;
}