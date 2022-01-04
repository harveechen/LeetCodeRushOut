#include <unordered_map>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <extra/utils.hpp>

using namespace std;

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *_head = new ListNode(-1, head);
        ListNode *pre = _head;
        ListNode *cur = head;
        ListNode *sentinel = head;
        while (n > 1) {
            sentinel = sentinel->next;
            n--;
        }
        while (sentinel->next) {
            pre = cur;
            cur = cur->next;
            sentinel = sentinel->next;
        }

        pre->next = cur->next;
        return _head->next;

    }
};

int main()
{
    string line;
    while (getline(cin, line))
    {
        ListNode* head = stringToListNode(line);
        getline(cin, line);
        int n = stringToInteger(line);
        
        ListNode* ret = Solution().removeNthFromEnd(head, n);

        string out = listNodeToString(ret);
        cout << out << endl;
    }
    return 0;
}