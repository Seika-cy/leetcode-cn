/*
 * @lc app=leetcode.cn id=6 lang=cpp
 *
 * [6] N 字形变换
 */

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
 public:
  string convert(string s, int numRows) {
    if (numRows == 1) return s;
    int n = numRows * 2 - 2;
    string res;
    for (auto i = 0; i < numRows; i++) {
      if (i == 0 || i == numRows - 1)
        for (int j = i; j < s.size(); j += n) res.push_back(s[j]);
      else {
        for (int j = i, k = n - j; j < s.size(); j += n, k += n) {
          res.push_back(s[j]);
          if (k < s.size()) {
            res.push_back(s[k]);
          }
        }
      }
    }

    return res;
  }
};
// @lc code=end

int main(int argc, char const *argv[]) {
  Solution s;
  // cout << s << endl;
  return 0;
}
