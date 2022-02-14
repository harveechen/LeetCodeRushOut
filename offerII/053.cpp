#include <unordered_map>
#include <unordered_set>
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
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        stack<TreeNode *> stk;
        TreeNode *curr = root;
        TreeNode *prev;

        while (!stk.empty() || curr != nullptr) {
            while (curr != nullptr) {
                stk.push(curr);
                curr = curr->left;
            }

            curr = stk.top();
            stk.pop();
            if (prev) return curr;

            if (curr == p) {
                prev = p;
            }

            curr = curr->right;
        }

        return nullptr;
    }
};

int main()
{
    string line;
    while (getline(cin, line))
    {
        TreeNode* root = stringToTreeNode(line);
        getline(cin, line);
        int p = stringToInteger(line);
        
        TreeNode* ret = Solution().inorderSuccessor(root, p);

        string out = treeNodeToString(ret);
        cout << out << endl;
    }
    return 0;
}