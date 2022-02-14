#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <limits.h>
#include <extra/utils.hpp>

using namespace std;

class Solution {
private:
    unordered_map<string, int> hmap;
    vector<vector<int>> edge;
    int id_num = 0;

public:
    void add_word(string w) {
        if (!hmap.count(w)) {
            hmap[w] = id_num++;
            edge.emplace_back();
        }
    }

    void add_edge(string w) {
        add_word(w);
        int id_w = hmap[w];

        for (char &ch : w) {
            char tmp = ch;
            ch = '*';

            add_word(w);
            int id_e = hmap[w];
            edge[id_w].push_back(id_e);
            edge[id_e].push_back(id_w);

            ch = tmp;
        }
    }

    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        for (auto &w : wordList) {
            add_edge(w);
        }
        add_edge(beginWord);
        if (!hmap.count(endWord)) return 0;

        vector<int> dis_begin(id_num, INT_MAX);
        vector<int> dis_end(id_num, INT_MAX);
        int id_begin = hmap[beginWord], id_end = hmap[endWord];

        queue<int> Q_begin;
        Q_begin.push(id_begin);
        dis_begin[id_begin] = 0;

        queue<int> Q_end;
        Q_end.push(id_end);
        dis_end[id_end] = 0;

        while (!Q_begin.empty() && !Q_end.empty()) {
            int begin_prev_size = Q_begin.size();
            for (int i = 0; i < begin_prev_size; i++) {
                int id = Q_begin.front();
                Q_begin.pop();

                if (dis_end[id] != INT_MAX) return (dis_begin[id] + dis_end[id]) / 2 + 1;

                for (auto e : edge[id]) {
                    if (dis_begin[e] == INT_MAX) {
                        dis_begin[e] = dis_begin[id] + 1;
                        Q_begin.push(e);
                    }
                }
             }

            int end_prev_size = Q_end.size();
            for (int i = 0; i < end_prev_size; i++) {
                int id = Q_end.front();
                Q_end.pop();

                if (dis_begin[id] != INT_MAX) return (dis_begin[id] + dis_end[id]) / 2 + 1;

                for (auto e : edge[id]) {
                    if (dis_end[e] == INT_MAX) {
                        dis_end[e] = dis_end[id] + 1;
                        Q_end.push(e);
                    }
                }
             }
        }

        return 0;
    }
};

int main()
{
    auto list = vector<string>{"hot","dot","dog","lot","log","cog"};
    cout << Solution().ladderLength("hit","cog", list);
}