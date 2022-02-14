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
    bool findTarget(TreeNode* root, int k) {
        unordered_set<int> S;
        stack<TreeNode *> stk;
        TreeNode *curr = root;

        while (!stk.empty() || curr != nullptr) {
            while (curr != nullptr) {
                stk.push(curr);
                curr = curr->left;
            }

            curr = stk.top();
            stk.pop();

            if (S.count(k-curr->val)) {
                return true;
            }
            S.insert(curr->val);
            curr = curr->right;
        }

        return false;
    }
};

int main()
{
    string line;
    while (getline(cin, line))
    {
        TreeNode* root = stringToTreeNode(line);
        getline(cin, line);
        int k = stringToInteger(line);
        
        bool ret = Solution().findTarget(root, k);

        string out = boolToString(ret);
        cout << out << endl;
    }
    return 0;
}