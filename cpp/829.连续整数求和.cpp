/*
 * @lc app=leetcode.cn id=829 lang=cpp
 *
 * [829] 连续整数求和
 */

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
 public:
  int consecutiveNumbersSum(int n) {
    int cnt = 1;
    for (int i = 1; i < n; i++) {
      int first = n / i - (i - 1) / 2;
      if(first<=0)
        break;
      int sum = 0;
      for (int j = first; j < n; j++) {
        sum += j;
        if (sum == n) {
          cnt++;
          break;
        } else if (sum > n)
          break;
      }
    }
    return cnt;
  }
};
// @lc code=end

int main(int argc, char const *argv[]) {
  Solution s;
  cout << s.consecutiveNumbersSum(3) << endl;
  return 0;
}
