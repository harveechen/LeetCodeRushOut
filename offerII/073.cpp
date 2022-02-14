#include <limits.h>

#include <algorithm>
#include <extra/utils.hpp>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

struct Cond {
 private:
  vector<int> &_data;
  int _target;

 public:
  inline int hour_need(vector<int> &piles, int K) {
    int total = 0;
    for (auto p : piles) {
      total += (p + K - 1) / K;
    }

    return total;
  };

  bool operator()(int mid) {
    return _target >= hour_need(_data, mid);
  };

  Cond(vector<int> &data, int target) : _data(data), _target(target){};
};

// search idx in [start, end) which satisfy the requirements
// mid as small as possible
template <typename Condition>
int binSearch(int start, int end, Condition &cond) {
  int mid = (start + end) / 2;

  while (end - start > 2) {
    // cond is satisfied or loose
    if (cond(mid)) {
      end = mid + 1;
    } else {
      start = mid + 1;  // else mid is exclude
    }

    mid = (start + end) / 2;
  }

  if (cond(start)) return start;

  return mid;
}

class Solution {
 public:
  int minEatingSpeed(vector<int> &piles, int h) {
    int piles_max = *max_element(piles.begin(), piles.end());
    if (h == piles.size()) return piles_max;

    int start = 1, end = piles_max + 1;
    auto cond = Cond(piles, h);
    return binSearch<decltype(cond)>(start, end, cond);
  }
};

int main() {
  string line;
  while (getline(cin, line)) {
    vector<int> piles = stringToIntegerVector(line);
    getline(cin, line);
    int h = stringToInteger(line);

    int ret = Solution().minEatingSpeed(piles, h);

    string out = to_string(ret);
    cout << out << endl;
  }
  return 0;
}