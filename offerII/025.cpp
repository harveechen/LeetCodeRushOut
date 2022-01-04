#include <unordered_map>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <extra/utils.hpp>

using namespace std;

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if (l1->val == 0) return l2;
        if (l2->val == 0) return l1;

        ListNode *pre1 = nullptr, *curr1 = l1;
        ListNode *pre2 = nullptr, *curr2 = l2;
        ListNode *tmp;
        while(curr1 != nullptr) {
            tmp = curr1->next;
            curr1->next = pre1;
            pre1 = curr1;
            curr1 = tmp;
        }

        while(curr2 != nullptr) {
            tmp = curr2->next;
            curr2->next = pre2;
            pre2 = curr2;
            curr2 = tmp;
        }

        int z = 0;
        ListNode* res = nullptr;
        while(pre1 != nullptr && pre2 != nullptr) {
            res = new ListNode((pre1->val + pre2->val+z)%10,res);
            z = (pre1->val + pre2->val+z)/10;
            pre1 = pre1->next;
            pre2 = pre2->next;
        }

        if (pre1 == nullptr) tmp = pre2;
        else tmp = pre1;

        while (tmp != nullptr) {
            res = new ListNode((tmp->val+z)%10, res);
            z = (tmp->val+z)/10;
            tmp = tmp->next;
        }

        if (z != 0) {
            res = new ListNode(z, res);
        }
        return res;
    }
};

int main()
{
    string line;
    while (getline(cin, line))
    {
        ListNode* l1 = stringToListNode(line);
        getline(cin, line);
        ListNode* l2 = stringToListNode(line);
        
        ListNode* ret = Solution().addTwoNumbers(l1, l2);

        string out = listNodeToString(ret);
        cout << out << endl;
    }
    return 0;
}