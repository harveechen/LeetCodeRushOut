#include <unordered_map>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <extra/utils.hpp>

using namespace std;

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *pre = nullptr;
        ListNode *cur = head;
        ListNode *tmp;
        while (cur != nullptr) {
            tmp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = tmp;
        }
        return pre;
    }
};

int main()
{
    string line;
    while (getline(cin, line))
    {
        ListNode* head = stringToListNode(line);
        
        ListNode* ret = Solution().reverseList(head);

        string out = listNodeToString(ret);
        cout << out << endl;
    }
    return 0;
}