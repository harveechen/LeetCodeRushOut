#include <unordered_map>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <extra/utils.hpp>

using namespace std;

class Trie
{
public:
    vector<Trie *> children;
    bool isEnd;
    /** Initialize your data structure here. */
    Trie() : children(26), isEnd(false) {}

    Trie* searchPrefix(string prefix) {
        Trie* node = this;
        for (char c : prefix) {
            c -= 'a';
            if (node->children[c] == nullptr) {
                return nullptr;
            }
            node = node->children[c];
        }
        return node;
    }

    /** Inserts a word into the trie. */
    void insert(string word)
    {
        Trie* node = this;
        for (char c : word) {
            c -= 'a';
            if (node->children[c] == nullptr) {
                node->children[c] = new Trie();
            }
            node = node->children[c];
        }
        node->isEnd = true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word)
    {
        Trie* node = this->searchPrefix(word);
        return node != nullptr && node->isEnd;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix)
    {
        return this->searchPrefix(prefix) != nullptr;
    }
};

int main()
{
    Trie *trie = new Trie();
    trie->insert("apple");
    cout << trie->search("apple") << endl;   // 返回 True
    cout << trie->search("app") << endl;     // 返回 False
    cout << trie->startsWith("app") << endl; // 返回 True
    trie->insert("app");
    cout << trie->search("app") << endl; // 返回 True
}