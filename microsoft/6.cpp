// nums var 1~N int max min

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

class Solution {
public:
    void pop_front(vector<int> &nums) {};
    void pop_back(vector<int> &nums) {};

    int pop_greatest_smallest(vector<int> &nums) {
        int N = nums.size();
        if (N < 2) perror("Illegal input");
        int min_val = INT_MAX, max_val = INT_MIN;
        int min_pos = -1, max_pos = -1;
        for (int i = 0; i < N - 1; i += 2) {
            int x = nums[i];
            int y = nums[i+1];
            if (x < y) {
                if (x < min_val) {
                    min_val = x;
                    min_pos = i;
                }
                if (y > max_val) {
                    max_val = y;
                    max_pos = i+1;
                }
            } else { // x >= y
                if (x > max_val) {
                    max_val = x;
                    max_pos = i;
                } else {
                    min_val = y;
                    min_pos = i+1;
                }
            }

        }

        if (N % 2) {
            int last = nums[N-1];
            if (last < min_val) {
                min_val = last;
                min_pos = N-1;
            } else if (last > max_val) {
                max_val = last;
                max_pos = N-1;
            }
        }
        
        int min_cnt = min_pos + 1 < (N - min_pos - 1) % N ? min_pos : (N - min_pos - 1) % N;

        // for (int i = 0; i < N; i++)
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