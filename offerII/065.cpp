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
    bool isWord;
    bool isEnd;
    int length;
public:
    Trie(): children(26), isWord(false), isEnd(true) {}

    void reverse_insert(string word) {
        Trie *node = this;
        for (int i = word.length() - 1; i >= 0; i--) {
            int pos = word[i] - 'a';
            if (node->children[pos] == nullptr) {
                node->children[pos] = new Trie();
            }
            node->isEnd = false;
            node = node->children[pos];
        }
        node->isWord = true;
        node->length = word.length();
    }

    int get_length() {
        int res = 0;
        stack<Trie *> stk;
        stk.push(this);
        Trie * tmp;
        while (!stk.empty()) {
            tmp = stk.top();
            stk.pop();
            // handle
            if (tmp->isWord && tmp->isEnd) {
                res += tmp->length + 1;
            }

            for (int i = 0; i < 26; i++) {
                if (tmp->children[i] != nullptr) {
                    stk.push(tmp->children[i]);
                }
            }
        }
        return res;
    }
};

class Solution {
public:
    Trie trie;
    int minimumLengthEncoding(vector<string>& words) {
        for (auto &w : words) {
            trie.reverse_insert(w);
        }
        return trie.get_length();
    }
};

int main()
{
    auto sln = new Solution();
    vector<string> input{"time", "me", "bell"};
    int out = sln->minimumLengthEncoding(input);
    cout << out << endl;
    return 0;
}