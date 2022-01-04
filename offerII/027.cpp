#include <unordered_map>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <extra/utils.hpp>

using namespace std;

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        vector<int> tmp;
        ListNode* p = head;
        while (p != nullptr) {
            tmp.push_back(p->val);
            p = p->next;
        }
        int i = 0, j = tmp.size()-1;
        while ( i< j) {
            if (tmp[i] != tmp[j]) {
                return false;
            }
            i++, j--;
        }
        return true;
    }
};

int main()
{
    string line;
    while (getline(cin, line))
    {
        ListNode* head = stringToListNode(line);
        
        bool ret = Solution().isPalindrome(head);

        string out = boolToString(ret);
        cout << out << endl;
    }
    return 0;
}