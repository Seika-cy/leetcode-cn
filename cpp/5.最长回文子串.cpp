/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 */

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
 public:
  string longestPalindrome(string s, int mode = 2) {
    string str;
    if (mode == 1)
      str = longestPalindrome1(s);
    else if (mode == 2)
      str = longestPalindrome2(s);
    return str;
  }

  string longestPalindrome1(string s) {
    auto n = s.size();
    if (n == 1) return s;
    vector<vector<bool>> dp(n, vector<bool>(n));
    for (size_t i = 0; i < n; i++) dp[i][i] = true;

    int max_len = 1;
    size_t sub_begin;
    for (auto len = 2; len <= n; len++) {
      size_t l, r;
      for (l = 0; l < n; l++) {
        r = l + len - 1;
        if (r >= n) break;
        if (s[l] != s[r])
          dp[l][r] = false;
        else {
          if (r - l < 3)
            dp[l][r] = true;
          else
            dp[l][r] = dp[l + 1][r - 1];
        }

        if (dp[l][r] && len > max_len) {
          max_len = len;
          sub_begin = l;
        }
      }
    }
    return s.substr(sub_begin, max_len);
  }

  pair<int, int> expandAroundCenter(string str, int left, int right) {
    int len = 1, max_len = 1;
    int sub_begin = left;
    while (left >= 0 && right < str.size()) {
      if (str[left] != str[right]) break;
      len = right - left + 1;
      if (len > max_len) {
        max_len = len;
        sub_begin = left;
      }
      left--;
      right++;
    }
    return pair<int, int>(sub_begin, max_len);
  }
  string longestPalindrome2(string s) {
    int sub_begin, max_len;
    for (int mid = 0; mid < s.size(); mid++) {
      auto [l1, len1] = expandAroundCenter(s, mid, mid);
      auto [l2, len2] = expandAroundCenter(s, mid, mid + 1);
      if (len1 > max_len) {
        sub_begin = l1;
        max_len = len1;
      }
      if (len2 > max_len) {
        sub_begin = l2;
        max_len = len2;
      }
    }
    return s.substr(sub_begin, max_len);
  }
  string longestPalindrome3(string s) {}
};
// @lc code=end

int main(int argc, char const *argv[]) {
  Solution s;
  cout << s.longestPalindrome("cbbd") << endl;
  return 0;
}
