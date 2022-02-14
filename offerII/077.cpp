#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <limits.h>
#include <extra/utils.hpp>

using namespace std;

class Solution {
public:
    ListNode* sortList(ListNode* head) {
        vector<ListNode *> arr;
        while (head != nullptr) {
            arr.push_back(head);
            head = head->next;
        }

        sort(arr.begin(), arr.end(), [](ListNode* &lh, ListNode * &rh)->bool{
            return lh->val < rh->val;
        });

        ListNode *root = new ListNode();
        ListNode *p = root;
        for (auto node : arr) {
            p->next = node;
            p = p->next;
        }
        return root->next;
    }
};

int main()
{
    string line;
    while (getline(cin, line))
    {
        ListNode* head = stringToListNode(line);
        
        ListNode* ret = Solution().sortList(head);

        string out = listNodeToString(ret);
        cout << out << endl;
    }
    return 0;
}