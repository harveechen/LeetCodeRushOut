#include <vector>
#include <string>

using namespace std;

string integerVectorToString(vector<int> list, int length = -1);
vector<int> stringToIntegerVector(string input);
vector<string> stringToStringVector(string input);
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

TreeNode *stringToTreeNode(string input);
int stringToInteger(string input);
string stringToString(string input);
string boolToString(bool input);
ListNode* stringToListNode(string input);
string listNodeToString(ListNode* node);