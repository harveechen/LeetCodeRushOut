#include <unordered_map>
#include <queue>
#include <stack>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <extra/utils.hpp>

using namespace std;

class MovingAverage {
public:
    /** Initialize your data structure here. */
    queue<int> Q;
    int capacity;
    double avg;
    MovingAverage(int size) {
        capacity = size;
        avg = 0.0;
    }
    
    double next(int val) {
        avg = avg * Q.size();
        if (Q.size() == capacity) {
            avg = avg - Q.front();
            Q.pop();
        } 
        Q.push(val);
        avg = (avg + val) / Q.size();
        return avg;
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