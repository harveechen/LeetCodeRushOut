#include <unordered_map>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <extra/utils.hpp>
#include <sstream>

using namespace std;

class Solution
{
public:
    int findMinDifference(vector<string> &timePoints)
    {
        vector<int> timeInt;
        for (auto &p : timePoints) {
            timeInt.push_back(stime2i(p));
        }
        
        sort(timeInt.begin(), timeInt.end());

        int tmp = timeInt[0];
        int minInterval = 12 * 60;
        for (int i = 1; i < timeInt.size(); i++) {
            minInterval = min({minInterval, minus(tmp, timeInt[i]), minus(timeInt[i], tmp)});
            tmp = timeInt[i];
        }

        minInterval = min({minInterval, minus(timeInt.front(), timeInt.back()), minus(timeInt.back(), timeInt.front())});

        return minInterval;
    }

    int minus(int a, int b)
    {
        return a - b >= 0 ? a - b : a - b + 24 * 60;
    }

    int stime2i(string time)
    {
        int res;
        stringstream ss;
        ss.str(time);

        string item;
        getline(ss, item, ':');
        res = (item[0] - '0') * 10 + (item[1]-'0');

        getline(ss, item, ':');

        res = res * 60 + (item[0] - '0') * 10 + (item[1]-'0');

        return res;
    }
};

int main()
{
    vector<string> timePoints{"00:00","04:00","22:00"};
    Solution().findMinDifference(timePoints);
}