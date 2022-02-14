#include <unordered_map>
#include <queue>
#include <stack>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>
#include <extra/utils.hpp>

using namespace std;

class Solution {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (root == nullptr) return "";
        stack<TreeNode *> stk;
        string ret = "";
        TreeNode *curr = root;
        while (!stk.empty() || curr != nullptr) {
            while (curr != nullptr) {
                stk.push(curr);
                ret += ",";
                ret += to_string(curr->val);
                curr = curr->left;
            }
            if (curr == nullptr) {
                ret += ",None";
            }
            curr = stk.top();
            stk.pop();
            curr = curr->right;
        }
        ret += ",None";
        ret.erase(ret.begin());

        return ret;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data == "") return nullptr;
        stringstream ss;
        ss.str(data);
        string item;

        getline(ss, item, ',');
        TreeNode *root = new TreeNode(stoi(item));
        TreeNode *curr = root, *tmp;
        stack<TreeNode *> stk;
        int val;
        while (!stk.empty() || curr != nullptr) {
            while (curr != nullptr) {
                stk.push(curr);
                getline(ss, item, ',');
                if (item == "None") 
                    tmp = nullptr;
                else
                    tmp = new TreeNode(stoi(item));
                curr->left = tmp;
                curr = curr->left;
            }
            
            curr = stk.top();
            stk.pop();
            getline(ss, item, ',');
            if (item == "None") 
                tmp = nullptr;
            else
                tmp = new TreeNode(stoi(item));
            curr->right = tmp;
            curr = curr->right;
        }

        return root;
    }

    string Codec(TreeNode* root) {
        TreeNode* tmp = deserialize(serialize(root));
        return treeNodeToString(tmp);
    }
};

int main()
{
    string line;
    while (getline(cin, line))
    {
        TreeNode* root = stringToTreeNode(line);
        
        string ret = Solution().Codec(root);

        string out = (ret);
        cout << out << endl;
    }
    return 0;
}