/*
 * @lc app=leetcode.cn id=7 lang=cpp
 *
 * [7] 整数反转
 */

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
 public:
  int reverse(int x) {
    string str = to_string(x);
    bool flag = false;
    if (str[0] == '-') {
      flag = true;
      str = str.substr(1);
    }
    std::reverse(str.begin(), str.end());
    if (flag) str = "-" + str;

    auto t = stod(str);
    if (t > INT32_MAX || t < INT32_MIN) return 0;
    return stoi(str);
  }
};
// @lc code=end

int main(int argc, char const *argv[]) {
  Solution s;
  // cout << s << endl;
  return 0;
}
