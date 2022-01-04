#include <unordered_map>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <extra/utils.hpp>

using namespace std;

class Solution {
public:
    void reorderList(ListNode* head) {
        ListNode *tmp = new ListNode(0, head);
        ListNode *fast = head, *slow = head;
        while(fast->next != nullptr) {
            fast = fast->next->next;
            slow = slow->next;
        }
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