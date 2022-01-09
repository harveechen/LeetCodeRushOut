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
    Node* next;

    Node() {}

    Node(int _val) {
        val = _val;
        next = NULL;
    }

    Node(int _val, Node* _next) {
        val = _val;
        next = _next;
    }
};

class Solution {
public:
    Node* insert(Node* head, int insertVal) {
        if (head == nullptr) {
            head = new Node(insertVal);
            head->next = head;
            return head;
        }

        Node *curr = head, *tmp = nullptr;

        while (curr != tmp) {
            if (tmp == nullptr) {
                tmp = head;
            }

            if ((curr->val <= insertVal && curr->next->val >= insertVal) || 
            (curr->val > curr->next->val && (insertVal <= curr->next->val || insertVal >= curr->val))) {
                Node *node = new Node(insertVal, curr->next);
                curr->next = node;
                return head;
            }

            curr = curr->next;
        }

        Node *node = new Node(insertVal, curr->next);
        curr->next = node;
        return head;
    }
};

int main()
{
    string line;
    while (getline(cin, line))
    {
        
    }
    return 0;
}