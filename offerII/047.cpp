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
    TreeNode* pruneTree(TreeNode* root) {
        stack<TreeNode*> stk;
        TreeNode *prev = nullptr;
        TreeNode *curr = root;
        bool prev_zero = false;

        while (!stk.empty() || curr != nullptr) {
            while (curr != nullptr) {
                stk.push(curr);
                curr = curr->left;
            }

            if (!stk.empty()) {
                curr = stk.top();

                if (curr->right == nullptr || curr->right == prev) {
                    // hanlde parent node
                    stk.pop();
                    if (curr->left  != nullptr && curr->left->val == -1) {
                        curr->left = nullptr;
                    }
                    if (curr->right != nullptr && curr->right->val == -1) {
                        curr->right = nullptr;
                    }

                    if (curr->val == 0 && curr->left == nullptr && curr->right == nullptr) {
                        curr->val = -1;
                    }

                    prev = curr;
                    curr = nullptr;
                } else {
                    curr = curr->right;
                }
            }
        }
        if (root->val == -1) 
            return {};
        else
            return root;
    }
};

int main()
{
    string line;
    while (getline(cin, line))
    {
        TreeNode* root = stringToTreeNode(line);
        
        TreeNode* ret = Solution().pruneTree(root);

        string out = treeNodeToString(ret);
        cout << out << endl;
    }
    return 0;
}