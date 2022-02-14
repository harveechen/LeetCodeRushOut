#include <unordered_map>
#include <map>
#include <unordered_set>
#include <queue>
#include <stack>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <extra/utils.hpp>

using namespace std;

class MyCalendar {
public:
    map<int, int> scher;
    MyCalendar() {

    }
    
    bool book(int start, int end) {
        auto it = scher.lower_bound(start);

        if (it != scher.end() && it->first < end) {
            return false;
        }

        if (it != scher.begin() && (--it)->second < start) {
            return false;
        }

        scher[start] = end;
        return true;
    }
};

int main()
{
    auto obj = new MyCalendar();
    
    
    cout << obj->book(20, 30);
    cout << obj->book(15, 25);
    cout << obj->book(10, 20);
    
    return 0;
}