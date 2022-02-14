#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>
#include <vector>
#include <iostream>
#include <algorithm>
#include <memory>
#include <string>
#include <extra/utils.hpp>

using namespace std;

class Trie
{
private:
    /* data */
    vector<unique_ptr<Trie>> children;
    bool isWord;
public:
    Trie(): children(10), isWord(false) {}

    void insert(int word) {

    }

    Trie(Trie&& other): children(10), isWord(false) {
        children = move(other.children);
        isWord = other.isWord;

        other.isWord = false;
    } 

};


class Solution {
private:
    static constexpr int HIGHT_BIT = 30;
public:
    int findMaximumXOR(vector<int>& nums) {
        int x = 0;
        for (int i = HIGHT_BIT; i >= 0; i--) {
            unordered_set<int> seen;
            for (auto num : nums) {
                seen.insert(num >> i);
            }

            int x_next = (x << 1) + 1;
            bool is_found = false;
            for (auto num : nums) {
                if (seen.count(x_next ^ (num >> i))) {
                    is_found = true;
                    break;
                }
            }
            if (is_found) x = x_next;
            else x = x_next - 1;
        }
        return x;
    }
};

int main()
{
    string line;
    while (getline(cin, line))
    {
        vector<int> nums = stringToIntegerVector(line);
        
        int ret = Solution().findMaximumXOR(nums);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}