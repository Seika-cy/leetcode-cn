/*
 * @lc app=leetcode.cn id=43 lang=cpp
 *
 * [43] 字符串相乘
 */

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
 public:
  string multiply(string &num1, string &num2) {
    vector<int> vec(num1.size() + num2.size(), 0);
    for (int i = num1.size() - 1; i >= 0; i--) {
      for (int j = num2.size() - 1; j >= 0; j--) {
        vec[i + j + 1] += (num1[i] - '0') * (num2[j] - '0');
      }
    }
    for (int i = vec.size() - 1; i >= 0; i--) {
      if (vec[i] > 9) {
        vec[i - 1] += vec[i] / 10;
        vec[i] %= 10;
      }
    }

    string ret;
    bool flag = 1;
    for (int i = 0; i < vec.size(); i++) {
      if (flag) {
        if (vec[i] != 0) {
          flag = 0;
        } else {
          continue;
        }
      }
      ret.push_back(vec[i] + '0');
    }

    return flag ? "0" : ret;
  }
};
// @lc code=end

int main(int argc, char const *argv[]) {
  Solution s;
  string num1 = "123";
  string num2 = "456";
  cout << s.multiply(num1, num2) << endl;
  return 0;
}
