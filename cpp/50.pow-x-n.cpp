/*
 * @lc app=leetcode.cn id=50 lang=cpp
 *
 * [50] Pow(x, n)
 */

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
 public:
  double myPow(double x, int n) {
    if (x == 0) {
      return 0;
    }
    if (n == 0) {
      return 1;
    }

    unsigned int power = 0;
    bool flag = 0;

    if (n < 0) {
      power = -1L * n;
      flag = 1;
    } else {
      power = n;
      flag = 0;
    }

    double ret = 1;
    double t = x;
    while (power) {
      ret *= ((power & 1) ? t : 1);
      power >>= 1;
      t *= t;
    }

    return flag ? 1 / ret : ret;
  }
};
// @lc code=end

int main(int argc, char const *argv[]) {
  Solution s;
  // cout << s << endl;
  return 0;
}
