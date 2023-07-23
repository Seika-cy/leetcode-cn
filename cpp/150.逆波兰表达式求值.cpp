/*
 * @lc app=leetcode.cn id=150 lang=cpp
 *
 * [150] 逆波兰表达式求值
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
  int evalRPN(vector<string>& tokens) {
    stack<int> ss;
    for (const auto& token : tokens) {
      if (token == "+" || token == "-" || token == "*" || token == "/") {
        int rhs = ss.top();
        ss.pop();
        int lhs = ss.top();
        ss.pop();
        if (token == "+") {
          ss.push(lhs + rhs);
        } else if (token == "-") {
          ss.push(lhs - rhs);
        } else if (token == "*") {
          ss.push(lhs * rhs);
        } else if (token == "/") {
          ss.push(lhs / rhs);
        }
      } else {
        ss.push(std::stoi(token.data()));
      }
    }
    return ss.top();
  }
};
// @lc code=end

int main(int argc, char const* argv[]) {
  Solution s;
  // cout << s << endl;
  return 0;
}
