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
public:
    TreeNode* increasingBST(TreeNode* root) {
        stack<TreeNode *> stk;
        TreeNode *curr = root;
        TreeNode *res = new TreeNode();
        TreeNode *prev = res;
        while (!stk.empty() || curr != nullptr) {
            while (curr != nullptr)
            {
                stk.push(curr);
                curr = curr->left;
            }
            
            curr = stk.top();
            stk.pop();
            prev->right = curr;
            curr = curr->right;

            prev = prev->right;
            prev->left = nullptr;
        }
        return res;
    }
};

int main()
{
    string line;
    while (getline(cin, line))
    {
        TreeNode* root = stringToTreeNode(line);
        
        TreeNode* ret = Solution().increasingBST(root);

        string out = treeNodeToString(ret);
        cout << out << endl;
    }
    return 0;
}