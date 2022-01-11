#include <unordered_map>
#include <queue>
#include <stack>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <extra/utils.hpp>

using namespace std;

class RecentCounter {
public:
    queue<int> Q;
    const int interval = 3000;
    int sum = 0;
    RecentCounter() {
        
    }
    
    int ping(int t) {
        while (!Q.empty() && Q.front() + interval < t)
            Q.pop();
        Q.push(t);
        return Q.size();
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