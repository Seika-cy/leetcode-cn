/*
 * @lc app=leetcode.cn id=14 lang=cpp
 *
 * [14] 最长公共前缀
 */

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
 public:
  string longestCommonPrefix(vector<string> &strs) {
    int pre_len = strs[0].size();
    string &pre = strs[0];
    for (auto &str : strs) {
      if (str.empty()) return "";
      pre_len = pre_len < str.size() ? pre_len : str.size();
      for (size_t i = 0; i < pre_len; i++) {
        if (pre[i] != str[i]) {
          pre_len = i;
          break;
        }
      }
      if (pre_len == 0) return "";
    }
    return pre.substr(0, pre_len);
  }
};
// @lc code=end

int main(int argc, char const *argv[]) {
  Solution s;
  // cout << s << endl;
  return 0;
}
