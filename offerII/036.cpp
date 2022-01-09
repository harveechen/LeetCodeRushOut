#include <unordered_map>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <extra/utils.hpp>
#include <stack>

using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;
        for (auto str : tokens) {
            if (str == "+" || str == "-" || str == "*" || str == "/") {
                int left = stk.top(); stk.pop();
                int right = stk.top(); stk.pop();
                if (str == "+") {
                    stk.push(left+right);
                } else if (str == "-") {
                    stk.push(left-right);
                } else if (str == "*") {
                    stk.push(left*right);
                } else {
                    stk.push(left/right);
                }

            } else {
                int number = stoi(str);
                stk.push(number);
            }
        }

        return stk.top();
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