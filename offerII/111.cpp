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
#include <string.h>
#include <extra/utils.hpp>

using namespace std;

class Solution {
public:
    typedef pair<int, double> WeightedEdge;
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, int> lookup;
        
        int cnt = 0;
        double error = -1.0;
        vector<double> ret;
        // var to id
        for (auto &eq : equations) {
            if (lookup.count(eq[0]) == 0) {
                lookup[eq[0]] = cnt++;
            }
            if (lookup.count(eq[1]) == 0) {
                lookup[eq[1]] = cnt++;
            }
        }

        // build graph
        int n = equations.size();
        int len = lookup.size();
        vector<vector<WeightedEdge>> graph(len, vector<WeightedEdge>());
        for (int i = 0; i < n; i++) {
            int A_id = lookup[equations[i][0]];
            int B_id = lookup[equations[i][1]];
            graph[A_id].emplace_back(B_id, values[i]);
            graph[B_id].emplace_back(A_id, 1.0 / values[i]);
        }

        // floyd
        vector<vector<double>> val(len, vector<double>(len, error));
        

        for (int i = 0; i < n; i++) {
            int A_id = lookup[equations[i][0]];
            int B_id = lookup[equations[i][1]];
            val[A_id][B_id] = values[i];
            val[B_id][A_id] = 1.0 / values[i];
        }

        for (int k = 0; k < len; k++) {
            for (int i = 0; i < len; i++) {
                for (int j = 0; j < len; j++) {
                    if (val[i][k] > 0 && val[k][j] > 0) {
                        val[i][j] = val[i][k] * val[k][j];
                    }
                }
            }
        }

        // query
        for (auto &q : queries) {
            if (!lookup.count(q[0]) || !lookup.count(q[1])) {
                ret.push_back(error);
                continue;
            }
            int C_id = lookup[q[0]];
            int D_id = lookup[q[1]];

            ret.push_back(val[C_id][D_id]);
        }
        return ret;
    }
};

int main()
{
    vector<vector<string>> eqs{{"a", "b"}, {"c", "d"}};
    vector<double> vals{2.0, 3.0};
    vector<vector<string>> qries{{"a", "c"}, {"b", "d"}, {"b", "a"}, {"d", "c"}};
    Solution().calcEquation(eqs, vals, qries);
    return 0;
}