#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

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

void trimLeftTrailingSpaces(string &input)
{
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch)
                                       { return !isspace(ch); }));
}

void trimRightTrailingSpaces(string &input)
{
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch)
                        { return !isspace(ch); })
                    .base(),
                input.end());
}

TreeNode *stringToTreeNode(string input)
{
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    if (!input.size())
    {
        return nullptr;
    }

    string item;
    stringstream ss;
    ss.str(input);

    getline(ss, item, ',');
    TreeNode *root = new TreeNode(stoi(item));
    queue<TreeNode *> nodeQueue;
    nodeQueue.push(root);

    while (true)
    {
        TreeNode *node = nodeQueue.front();
        nodeQueue.pop();

        if (!getline(ss, item, ','))
        {
            break;
        }

        trimLeftTrailingSpaces(item);
        if (item != "null")
        {
            int leftNumber = stoi(item);
            node->left = new TreeNode(leftNumber);
            nodeQueue.push(node->left);
        }

        if (!getline(ss, item, ','))
        {
            break;
        }

        trimLeftTrailingSpaces(item);
        if (item != "null")
        {
            int rightNumber = stoi(item);
            node->right = new TreeNode(rightNumber);
            nodeQueue.push(node->right);
        }
    }
    return root;
}

int stringToInteger(string input)
{
    return stoi(input);
}

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