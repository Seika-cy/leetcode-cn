/*
 * @lc app=leetcode.cn id=59 lang=cpp
 *
 * [59] 螺旋矩阵 II
 */

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
 public:
  vector<vector<int>> generateMatrix(int n) {
    vector<vector<int>> ret(n, vector<int>(n, 0));
    int cnt = 1;
    int loop = n / 2;
    bool odd_flag = n % 2;

    int start_x = 0, start_y = 0;
    int offset = 0;
    while (loop--) {
      for (int i = start_x, j = start_y; j < n - offset; j++) {
        ret[i][j] = cnt++;
      }
      for (int i = start_x + 1, j = n - offset - 1; i < n - offset; i++) {
        ret[i][j] = cnt++;
      }
      for (int i = n - offset - 1, j = n - offset - 2; j >= offset; j--) {
        ret[i][j] = cnt++;
      }
      for (int i = n - offset - 2, j = offset; i > start_x; i--) {
        ret[i][j] = cnt++;
      }

      start_x++;
      start_y++;
      offset++;
    }

    if (odd_flag) {
      ret[n / 2][n / 2] = cnt;
    }
    return ret;
  }
};
// @lc code=end

int main(int argc, char const *argv[]) {
  Solution s;
  // cout << s << endl;
  return 0;
}
