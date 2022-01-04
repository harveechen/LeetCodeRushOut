#include <unordered_map>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <extra/utils.hpp>

using namespace std;

class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};

class Solution {
public:
    Node* flatten(Node* head) {
        if (head == nullptr) return nullptr;
        return df(head);
    }

    Node* df(Node* head) {
        Node *tmp = head->next;
        if (head->child != nullptr) { 
            head->next =  head->child;
            Node *tail = df(head->child);
            tail->next = tmp;
        }

        if (tmp != nullptr) {
            return df(tmp)
        } else {
            return head;
        }
    }
};

int main()
{
    string line;
    while (getline(cin, line))
    {
        TreeNode* head = stringToTreeNode(line);
        
        TreeNode* ret = Solution().flatten(head);

        string out = treeNodeToString(ret);
        cout << out << endl;
    }
    return 0;
}