#include <unordered_map>
#include <queue>
#include <stack>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <extra/utils.hpp>

using namespace std;

class Trie {
private:
    vector<Trie *> children;
    int cnt;
public:
    Trie(): children(27), cnt(0) {}
    void insert(string word) {
        Trie *node = this;
        for (auto &ch : word) {
            int pos = ch-'`';
            
            if (node->children[pos] == nullptr) {
                node->children[pos] = new Trie();
            }

            node = node->children[pos];
        }
        node->cnt += 1;
    }

    int get(string word) {
        Trie *node  = this;
        for (auto &ch : word) {
            int pos = ch - '`';
            if (node->children[pos] == nullptr) {
                return 0;
            }   
            node = node->children[pos];
        }
        return node->cnt;
    }
};

class MagicDictionary {
private:
    Trie trie;
public:
    /** Initialize your data structure here. */
    MagicDictionary() {

    }

    vector<string> getNeighbor(string word) {
        vector<string> res;
        for (int i = 0; i < word.size(); i++) {
            string tmp = word;
            tmp[i] = '`';
            res.push_back(tmp);
        }
        return res;
    }
    
    void buildDict(vector<string> dictionary) {
        for (auto w : dictionary) {
            for (auto n : getNeighbor(w)) {
                trie.insert(n);
            }
            trie.insert(w);
        }
    }
    
    bool search(string searchWord) {
        int flag = false;

        if (trie.get(searchWord) == 1) {
            flag = true;
        }

        for (auto n : getNeighbor(searchWord)) {
            int cnt = trie.get(n);
            if (cnt > 1 || (cnt == 1 && !flag)) {
                return true;
            }
        }
            
        return false;
    }
};

int main()
{
    MagicDictionary* obj = new MagicDictionary();
    obj->buildDict(vector<string>{"a","b"});
    bool param_2 = obj->search("ab");
    cout << param_2 << endl;
    return 0;
}