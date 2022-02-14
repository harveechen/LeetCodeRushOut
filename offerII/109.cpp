#include <algorithm>
#include <extra/utils.hpp>
#include <iostream>
#include <limits.h>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
  public:
    struct AStar {
        string status;
        int f, g, h;
        static int getH(const string &status, string &target) {
            int total = 0;
            for (int i = 0; i < 4; i++) {
                int diff = abs(int(status[i]) - int(target[i]));
                total += min(diff, 10 - diff);
            }

            return total;
        }
        AStar(const string &s, string &target, int gval)
            : status{s}, g{gval}, h{getH(s, target)} {
            f = g + h;
        }

        bool operator<(const AStar &other) const { return f > other.f; }
    };
    int openLock(vector<string> &deadends, string target) {
        if (target == "0000")
            return 0;

        unordered_set<string> dead(deadends.begin(), deadends.end());

        if (dead.count("0000"))
            return -1;

        auto num_prev = [](char x) -> char { return x == '0' ? '9' : x - 1; };

        auto num_succ = [](char x) -> char { return x == '9' ? '0' : x + 1; };

        auto get = [&](string &status) -> vector<string> {
            vector<string> ret;
            for (auto &ch : status) {
                char tmp = ch;
                ch = num_prev(tmp);
                ret.push_back(status);
                ch = num_succ(tmp);
                ret.push_back(status);
                ch = tmp;
            }

            return ret;
        };

        priority_queue<AStar> q;
        q.emplace("0000", target, 0);

        unordered_set<string> vis{"0000"};

        while (!q.empty()) {
            auto curr = q.top();
            q.pop();

            for (auto &&next_status : get(curr.status)) {
                if (!vis.count(next_status) && !dead.count(next_status)) {
                    if (next_status == target)
                        return curr.g + 1;
                    q.emplace(next_status, target, curr.g + 1);
                    vis.insert(move(next_status));
                }
            }
        }

        return -1;
    }
};

int main() {
    vector<string> dead{"0201", "0101", "0102", "1212", "2002"};
    cout << Solution().openLock(dead, "0202");
}