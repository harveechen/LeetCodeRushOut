#include <unordered_map>
#include <queue>
#include <stack>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <extra/utils.hpp>

using namespace std;

class KthLargest {
private:
    priority_queue<int, vector<int>, greater<int>> heap;
    int MAX_SIZE;
public:
    KthLargest(int k, vector<int>& nums) {
        MAX_SIZE = k;
        for (auto num : nums) {
            add(num);
        }
    }
    
    int add(int val) {
        heap.push(val);
        if (heap.size() > MAX_SIZE)
            heap.pop();
        return heap.top();
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