#include <unordered_map>
#include <queue>
#include <stack>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <extra/utils.hpp>

using namespace std;

class Solution {
private:
    unordered_map<long long, int> prefix_sum_map;
public:
    int pathSum(TreeNode* root, int targetSum) {
        prefix_sum_map[0] = 1;
        return dfs(root, 0, targetSum);
    }

    // up to node root, number of path seg satisfy requirement
    // inform with pre sum
    int dfs(TreeNode* root, long long prefix_sum, const int &targetsum) {
        if (root == nullptr) return 0;
        int ret = 0;
        prefix_sum += root->val;

        if (prefix_sum_map.count(prefix_sum-targetsum)) {
            ret += prefix_sum_map[prefix_sum-targetsum];
        }
        prefix_sum_map[prefix_sum]++;
        ret += dfs(root->left, prefix_sum, targetsum);
        ret += dfs(root->right, prefix_sum, targetsum);
        prefix_sum_map[prefix_sum]--;

        return ret;
    }
};

int main()
{
    string line;
    while (getline(cin, line))
    {
        TreeNode* root = stringToTreeNode(line);
        getline(cin, line);
        int targetSum = stringToInteger(line);
        
        int ret = Solution().pathSum(root, targetSum);

        string out = to_string(ret);
        cout << out << endl;
        
    }
    return 0;
}