#include <unordered_map>
#include <stack>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <extra/utils.hpp>

using namespace std;

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> stk;
        for (auto star : asteroids) {
            if (stk.empty() || stk.top() * star > 0 || (stk.top() < 0 && star > 0)) {
                stk.push(star);
            } else if (star < 0 && stk.top() > 0) {
                if (abs(star) < stk.top()) continue;
                else if (abs(star) == stk.top()) {
                    stk.pop();
                    continue;
                } else {
                    stk.pop();
                    while (!stk.empty()) {
                        if ((stk.top() * star < 0) && (abs(star) > stk.top()))
                            stk.pop();
                        else
                            break;
                    }
                    if (stk.empty()) stk.push(star);
                    else if (stk.top() * star > 0) stk.push(star);
                    else if (stk.top() + star == 0) stk.pop();
                    else if (stk.top() > abs(star)) continue;
                }
            }
        }

        vector<int> res(stk.size());
        for (int i = stk.size()-1; i >= 0; i--) {
            res[i] = stk.top();
            stk.pop();
        }

        return res;
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