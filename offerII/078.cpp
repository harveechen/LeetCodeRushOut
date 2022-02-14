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
    static bool cmp(ListNode *&lh, ListNode*&rh) {
        return lh->val > rh->val;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, decltype(&cmp)> heap(cmp);
        ListNode *head = new ListNode();
        ListNode *p = head;
        for (auto &root : lists) {
            if (root == nullptr) continue;
            heap.push(root);
        }
        while (!heap.empty()) {
            ListNode *tmp = heap.top();
            heap.pop();
            p->next = tmp;
            p = p->next;

            tmp = tmp->next;
            if (tmp != nullptr) {
                heap.push(tmp);
            }
        }
        return head->next;
    }
};

ListNode* create(vector<int> nums) {
    ListNode *head = new ListNode();
    ListNode *p = head;

    for (auto &num : nums) {
        p->next = new ListNode(num);
        p = p->next;
    }
    return head->next;
}

int main()
{
    ListNode *L1 = create(vector<int>{1,4,5});
    ListNode *L2 = create(vector<int>{1,3,4});
    ListNode *L3 = create(vector<int>{2,6});
    vector<ListNode*> input{L1, L2, L3};
    Solution().mergeKLists(input);

    return 0;
}