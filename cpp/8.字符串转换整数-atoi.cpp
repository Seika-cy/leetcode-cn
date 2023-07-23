/*
 * @lc app=leetcode.cn id=8 lang=cpp
 *
 * [8] 字符串转换整数 (atoi)
 */

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
 public:
  int myAtoi(string s) {
    long long num = 0;
    bool sign_flag = true;
    bool num_flag = false;
    string str;
    for (auto ch : s) {
      if (ch >= '0' && ch <= '9') {
        str.push_back(ch);
        num_flag = true;
      } else if (!num_flag) {
        if (ch == ' ')
          continue;
        else if (ch == '-' || ch == '+') {
          if (ch == '-') sign_flag = false;
          num_flag = true;
        } else
          break;
      } else
        break;
    }
    long long t = 0;
    for (size_t i = 0; i < str.size(); i++) {
      num *= 10;
      num += str[i] - '0';
      t = (sign_flag) ? num : num * (-1);
      if (sign_flag && t > INT32_MAX) return INT32_MAX;
      if (!sign_flag && t < INT32_MIN) return INT32_MIN;
    }
    return t;
  }
};
// @lc code=end

int main(int argc, char const *argv[]) {
  Solution s;
  cout << s.myAtoi("words and 987") << endl;
  return 0;
}
