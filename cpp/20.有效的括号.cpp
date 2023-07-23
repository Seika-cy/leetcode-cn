/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 */

#include <algorithm>
#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
 public:
  bool isValid(string s) {
    stack<char> ss;
    for (auto &ch : s) {
      if (ch == '(' || ch == '[' || ch == '{')
        ss.push(ch);
      else {
        if (ss.empty()) return false;
        if ((ss.top() == '(' && ch == ')') || (ss.top() == '[' && ch == ']') ||
            (ss.top() == '{' && ch == '}')) {
          ss.pop();
        } else
          return false;
      }
    }
    return ss.empty() ? true : false;
  }
};
// @lc code=end

int main(int argc, char const *argv[]) {
  Solution s;
  cout << s.isValid("()[]{}") << endl;
  return 0;
}
