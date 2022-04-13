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

int binary_search(vector<int> &arr, int target, int lh, int rh) {
    int mid = (lh + rh) / 2;
    while (lh <= rh) {
        if (arr[mid] == target) return mid;
        else if (arr[mid] > target) rh = mid - 1;
        else lh = mid + 1;
    }
    return -1;
}

int solution(vector<int> &arr, int target) {
    int n = arr.size();
    int lh_min = arr[0];
    int rh_max = arr[n-1];
    int lh = 0, rh = n - 1;
    if (target == lh_min) return 0;
    if (target == rh_max) return n-1;

    if (target > lh_min) {
        while (lh <= rh) { // zuo xu lie 
            int mid = (lh+rh) / 2;
            if (arr[mid] == target) return mid;
            if (arr[mid] > target) {
                return binary_search(arr, target, lh, mid-1);
            } else {
                if (arr[mid] > rh_max) lh = mid + 1;  
                else rh = mid - 1;    // 6789 12345
            }
        }
    } else if (target < rh_max) {
        while (lh <= rh) {
            int mid = (lh+rh) / 2;
            if (arr[mid] == target) return mid;
            if (arr[mid] < target) {
                return binary_search(arr, target, mid+1, rh);
            } else {
                if (arr[mid] < lh_min) rh = mid - 1;
                else lh = mid + 1;
            }
        }
    } 

    return -1;
}


int main()
{
    string line;
    while (getline(cin, line))
    {
        vector<int> arr = stringToIntegerVector(line);
        getline(cin, line);
        int target = stringToInteger(line);
        cout << solution(arr, target) << endl;
    }
    return 0;
}