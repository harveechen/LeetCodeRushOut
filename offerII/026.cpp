#include <unordered_map>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <extra/utils.hpp>

using namespace std;

class Solution
{
public:
    void reorderList(ListNode *head)
    {
        if (head->next == nullptr || head->next->next == nullptr)
            return;
        head = new ListNode(0, head);
        ListNode *fast = head, *slow = head;
        while (fast != nullptr && fast->next != nullptr)
        {
            fast = fast->next->next;
            slow = slow->next;
        }

        ListNode *pre = nullptr, *curr = slow->next;
        slow->next = nullptr;
        ListNode *tmp;
        while (curr != nullptr)
        {
            tmp = curr->next;
            curr->next = pre;
            pre = curr;
            curr = tmp;
        }

        head = head->next;
        ListNode *left = head, *right = pre;
        ListNode *res = new ListNode(0);
        curr = res;
        while (left != nullptr || right != nullptr)
        {
            if (left != nullptr)
            {
                tmp = left;
                left = left->next;
                curr->next = tmp;
                curr = curr->next;
            }
            if (right != nullptr)
            {
                tmp = right;
                right = right->next;
                curr->next = tmp;
                curr = curr->next;
            }
        }
    }
};

int main()
{
    string line;
    while (getline(cin, line))
    {
        ListNode *head = stringToListNode(line);
        Solution().reorderList(head);

        string out = listNodeToString(head);
        cout << out << endl;
    }
    return 0;
}