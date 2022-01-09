#include <unordered_map>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <extra/utils.hpp>

using namespace std;

class Solution {
public:
    unordered_map<char, int> _hash;
    bool isAlienSorted(vector<string>& words, string order) {
        if (words.size() <= 1) return true;
        
        int idx = 0;
        for (const char &ch : order) {
            _hash[ch] = idx++;
        }

        string tmp = words[0];
        for (int i = 1; i < words.size(); i++) {
            if (!compare(tmp, words[i])) return false;
            tmp = words[i];
        }
        return true;
    }

    bool compare(string a, string b) {
        int cnt = min(a.size(), b.size());
        for (int i = 0; i < cnt; i++) {
            if (_hash.count(a[i]) == 0 || _hash.count(b[i]) == 0) return false;
            if (_hash[a[i]] > _hash[b[i]]) return false;
            else if (_hash[a[i]] < _hash[b[i]]) return true;
        }

        if (a.size() > b.size()) return false;
        return true;
    }
};

int main()
{

    auto words = vector<string>{"zirqhpfscx","zrmvtxgelh","vokopzrtc","nugfyso","rzdmvyf","vhvqzkfqis","dvbkppw","ttfwryy","dodpbbkp","akycwwcdog"};
    auto order = "khjzlicrmunogwbpqdetasyfvx";
    cout << Solution().isAlienSorted(words, order);
}