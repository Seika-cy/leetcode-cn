/*
 * @lc app=leetcode.cn id=22 lang=cpp
 *
 * [22] 括号生成
 */

#include <algorithm>
#include <functional>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
 public:
  vector<string> generateParenthesis(int n) {
    vector<string> res;
    function<void(string, int, int)> dfs;
    dfs = [&](string str, int l, int r) {
      if (l > n || r > n || l < r) return;
      if (l == n && r == n) {
        res.push_back(str);
        return;
      }
      dfs(str + '(', l + 1, r);
      dfs(str + ')', l, r + 1);
    };
    dfs("", 0, 0);
    return res;
  }
};
// @lc code=end

int main(int argc, char const *argv[]) {
  Solution s;
  // cout << s << endl;
  return 0;
}
