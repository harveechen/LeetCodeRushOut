#include <unordered_map>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <extra/utils.hpp>
#include <sstream>
#include <queue>

using namespace std;

class Node
{
public:
    int val;
    Node *prev;
    Node *next;
    Node *child;

    Node(int x) : val(x), prev(nullptr), next(nullptr), child(nullptr) {}
};

class Solution
{
public:
    Node *flatten(Node *head)
    {
        dfs(head);
        return head;
    }

    Node *dfs(Node *head)
    {
        Node *curr = head;
        Node *last = nullptr;

        while (curr) {
            Node* next = curr->next;
            if (curr->child != nullptr) {
                Node *child_last = dfs(curr->child);
                
                curr->next = curr->child;
                curr->child->prev = curr;

                if (next != nullptr) {
                    child_last->next = next;
                    next->prev = child_last;
                }

                curr->child = nullptr;
                last = child_last;

            } else {
                last = curr;
            }
            curr = next;
        }
        return last;
    }
};

Node *stringToNode(string input)
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
    Node *root = new Node(stoi(item));
    deque<Node *> nodeQueue;
    nodeQueue.push_back(root);

    while (true)
    {
        Node *node = nodeQueue.back();

        if (!getline(ss, item, ','))
        {
            break;
        }

        trimLeftTrailingSpaces(item);
        if (item != "null")
        {
            int nextNumber = stoi(item);
            node->next = new Node(nextNumber);
            nodeQueue.push_back(node->next);
        }
        else
        {
            node->next = nullptr;
            while (true)
            {
                if (!getline(ss, item, ','))
                {
                    break;
                }

                trimLeftTrailingSpaces(item);
                if (item == "null") {
                    nodeQueue.pop_front();
                } else {
                    Node *node = nodeQueue.front();
                    int childNumber = stoi(item);
                    node->child = new Node(childNumber);
                    nodeQueue.pop_front();
                    nodeQueue.push_front(node->child);
                    break;
                }
            }
        }
    }
}

int main()
{
    string line;
    while (getline(cin, line))
    {
        Node *head = stringToNode(line);

        Node *ret = Solution().flatten(head);

        // string out = NodeToString(ret);
        // cout << out << endl;
    }
    return 0;
}