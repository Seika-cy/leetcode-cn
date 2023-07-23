/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
 public:
  int lengthOfLongestSubstring(string s) {
    int l_cur = 0, r_cur = 0;
    int max = 0;

    while (r_cur < s.size()) {
      for (size_t i = l_cur; i < r_cur; i++) {
        if (s[r_cur] == s[i]) {
          l_cur = i + 1;
          break;
        }
      }
      r_cur++;
      max = (r_cur - l_cur) > max ? (r_cur - l_cur) : max;
    }
    return max;
  }
};
// @lc code=end

int main(int argc, char const *argv[]) {
  Solution s;
  cout << s.lengthOfLongestSubstring(" ") << endl;
  return 0;
}
