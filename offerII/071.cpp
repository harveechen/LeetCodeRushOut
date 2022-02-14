#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <extra/utils.hpp>
#include <random>

using namespace std;

class Solution {
public:
    vector<int> pre;
    uniform_int_distribution<int> dis;
    mt19937 gen;

    Solution(vector<int> &w): gen(random_device{}()), dis(1, accumulate(w.begin(), w.end(), 0)) {
        partial_sum(w.begin(), w.end(), pre);
    }

    int pickIndex() {
        int x = dis(gen);
        return lower_bound(pre.begin(), pre.end(), x) - pre.begin();
    }
};

int main()
{
    string line;
    while (getline(cin, line))
    {
        
    }
    return 0;
}