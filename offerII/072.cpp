#include <limits.h>

#include <algorithm>
#include <extra/utils.hpp>
#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

// search idx in [start, end) which satisfy the requirements

template <typename Condition, bool minimize = true>
int binSearch(int start, int end, Condition &cond) {
  int mid = (start + end) / 2;
  while (end - start > 2) {
    // cond is satisfied or loose
    if (cond(mid)) {
      if (minimize) {
        end = mid + 1; // mid as small as possible
      } else {
        start = mid;
      }

    } else {
      if (minimize) {
        start = mid + 1; // else mid is exclude
      } else {
        end = mid;
      }
    }

    mid = (start + end) / 2;
  }

  if (!minimize) {
    if (cond(mid))
      return mid;
    return start;
  } else {
    if (cond(start))
      return start;

    return mid;
  }
}

struct Cond {
private:
  int _target;

public:
  bool operator()(int mid) { return (long)mid * mid <= _target; }

  Cond(int target) : _target(target){};
};

class Solution {
public:
  int mySqrt(int x) {
    int start = 0, end = min(x, INT_MAX - 1) + 1;

    auto cond = Cond(x);
    return binSearch<decltype(cond), false>(start, end, cond);
  }
};

int main() { Solution().mySqrt(8); }