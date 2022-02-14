#include <unordered_map>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>
#include <extra/utils.hpp>

using namespace std;

class Trie {
private:
    vector<Trie *> children;
    bool isEnd;
public:
    Trie(): children(26), isEnd(false) {}

    void insert(string word) {
        Trie *node = this;
        for (auto &ch : word) {
            if (node->children[ch-'a'] == nullptr) {
                node->children[ch-'a'] = new Trie();
            }
            node = node->children[ch-'a'];
        }
        node->isEnd = true;
    }

    string searchRoot(string word) {
        Trie *node = this;
        string res = "";
        for (auto &ch : word) {
            if (node->isEnd) {
                return res;
            }
            if (node->children[ch-'a'] == nullptr) { 
                break;
            }
                
            res += ch;
            node = node->children[ch-'a'];
        }

        return word;
    }
};


class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        auto trie = Trie();
        for (auto word : dictionary) {
            trie.insert(word);
        }
        string res = "";
        stringstream ss;
        string item;
        ss.str(sentence);
        while (true) {
            if (!getline(ss, item, ' ')) {
                break;
            }
            res += " ";
            res += trie.searchRoot(item);
        }
        res.erase(res.begin());
        return res;
    }
};

int main()
{
    string line;
    while (getline(cin, line))
    {
        vector<string> a = {"a", "aa", "aaa", "aaaa"};
        string b = "a aa a aaaa aaa aaa aaa aaaaaa bbb baba ababa";
        string out = Solution().replaceWords(a, b);
        cout << out << endl;
    }
    return 0;
}