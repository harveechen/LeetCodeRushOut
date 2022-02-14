#include <unordered_map>
#include <queue>
#include <stack>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <extra/utils.hpp>

using namespace std;

class CBTInserter {
public:
    vector<TreeNode*> vec;
    CBTInserter(TreeNode* root) {
        queue<TreeNode*> Q;
        Q.push(root);
        while (!Q.empty()) {
            TreeNode* tmp = Q.front();
            Q.pop();
            vec.push_back(tmp);
            if (tmp->left != nullptr) Q.push(tmp->left);
            if (tmp->right != nullptr) Q.push(tmp->right);
        }
    }
    
    int insert(int v) {
        TreeNode *tmp = new TreeNode(v);
        vec.push_back(tmp);
        int total = vec.size();
        int parent_idx = total/2; // start from 1
        TreeNode* parent = vec[parent_idx - 1];
        if (parent_idx * 2 == total)
            parent->left = tmp;
        else
            parent->right = tmp;

        return parent->val;
    }
    
    TreeNode* get_root() {
        return vec.front();
    }
};

int main()
{
    TreeNode *root = new TreeNode(1);
    auto obj = new CBTInserter(root);
    obj->insert(2);
    obj->get_root();
    return 0;
}