#include <iostream>
#include <vector>

using namespace std; 

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        rowIndex++;
        vector<int> res(rowIndex);
        int k, i;
        for (k = 0; k < rowIndex; k++) {
            res[0] = res[k] = 1;
            for (i = k-1; i > 0; i--) {
                res[i] += res[i-1];
            }
        }
        return res;
    }
};


int main(int argc, char *argv[]) {
    Solution s;
    s.getRow(3);
}