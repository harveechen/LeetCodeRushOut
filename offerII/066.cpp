#include <unordered_map>
#include <queue>
#include <stack>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <extra/utils.hpp>

using namespace std;

class MapSum
{
private:
    unordered_map<string, int> _map;
    class Trie
    {
    public:
        vector<Trie *> children;
        bool isWord = false;
        int prefix_sum = 0;
        Trie() : children(26) {}
    };

    Trie *trie = new Trie();
    
    int get_prefix_sum(string prefix)
    {
        Trie *node = trie;
        for (auto &ch : prefix)
        {
            int pos = ch - 'a';
            if (node->children[pos] == nullptr)
                return 0;
            node = node->children[pos];
        }
        return node->prefix_sum;
    }

public:
    /** Initialize your data structure here. */
    MapSum()
    {
    }

    void insert(string word, int val)
    {
        int update;
        if (_map.count(word) == 0)
        {
            update = val;
        }
        else
        {
            update = val - _map.at(word);
        }

        Trie *node = trie;
        for (auto &ch : word)
        {
            int pos = ch - 'a';
            if (node->children[pos] == nullptr)
                node->children[pos] = new Trie();
            node = node->children[pos];
            node->prefix_sum += update;
        }
        node->isWord = true;

        _map[word] = val;
    }

    int sum(string prefix)
    {
        return get_prefix_sum(prefix);
    }
};

int main()
{
    MapSum *obj = new MapSum();
    obj->insert("apple", 3);
    obj->insert("app", 2);
    int param_2 = obj->sum("ap");
    cout << param_2 << endl;
    return 0;
}