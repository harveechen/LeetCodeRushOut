#include <vector>
#include <string>

using namespace std;

vector<int> stringToIntegerVector(string input);
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