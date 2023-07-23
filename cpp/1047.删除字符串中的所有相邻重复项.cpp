/*
 * @lc app=leetcode.cn id=1047 lang=cpp
 *
 * [1047] 删除字符串中的所有相邻重复项
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
  string removeDuplicates(string &s) {
    string ret;

    for (auto &ch : s) {
      if (ret.empty()) {
        ret.push_back(ch);
      } else {
        if (ret.back() == ch) {
          ret.pop_back();
        } else {
          ret.push_back(ch);
        }
      }
    }
    return ret;
  }
};
// @lc code=end

int main(int argc, char const *argv[]) {
  Solution s;
  //   cout << s.removeDuplicates("abbaca") << endl;
  return 0;
}
