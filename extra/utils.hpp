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
TreeNode *stringToTreeNode(string input);
int stringToInteger(string input);
string stringToString(string input);
string boolToString(bool input);