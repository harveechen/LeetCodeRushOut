#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <queue>
#include <unordered_map>
#include <extra/utils.hpp>

using namespace std;

class Solution
{
public:
    int cnt = 0;
    int sum;
    unordered_map<int, int> prefix;
    int pathSum(TreeNode *root, int targetSum)
    {
        // my solution
        // if (root == NULL) return 0;
        // sum = targetSum;
        // get(root);
        // return cnt;

        // 前缀树
        prefix[0] = 1;
        return dfs(root, 0, targetSum);
    }

    int dfs(TreeNode *root, long long curr, int targetSum)
    {
        if (root == NULL)
            return 0;
        int ret = 0;
        curr += root->val;
        
        if (prefix.count(curr - targetSum))
        {
            ret += prefix[curr - targetSum];
        }

        prefix[curr]++;
        ret += dfs(root->left, curr, targetSum);
        ret += dfs(root->right, curr, targetSum);
        prefix[curr]--;
        return ret;
    }

    vector<int> get(TreeNode *root)
    {
        vector<int> left_arr(0);
        vector<int> right_arr(0);
        vector<int> res = {root->val};

        if (root->val == sum)
            cnt++;

        if (root->left != NULL)
        {
            left_arr = get(root->left);
            for (auto val : left_arr)
            {
                if ((val + root->val) == sum)
                {
                    cnt++;
                };
                res.push_back(val + root->val);
            }
        }
        if (root->right != NULL)
        {
            right_arr = get(root->right);
            for (auto val : right_arr)
            {
                if ((val + root->val) == sum)
                {
                    cnt++;
                };
                res.push_back(val + root->val);
            }
        }
        return res;
    }
};

int main()
{
    string line;
    while (getline(cin, line))
    {
        TreeNode *root = stringToTreeNode(line);
        getline(cin, line);
        int targetSum = stringToInteger(line);

        int ret = Solution().pathSum(root, targetSum);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}