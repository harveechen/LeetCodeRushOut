#include <unordered_map>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <extra/utils.hpp>

using namespace std;

class RandomizedSet {
public:
    /** Initialize your data structure here. */
    unordered_map<int, int> _hash;
    vector<int> data;
    RandomizedSet() {

    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if (_hash.count(val) == 1) return false;
        _hash[val] = data.size();
        data.push_back(val);
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if (_hash.count(val) == 0) return false;
        _hash[data.back()] = _hash[val];
        data[_hash[val]] = data.back();
        _hash.erase(val);
        data.pop_back();
        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        return data[rand() % data.size()];
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