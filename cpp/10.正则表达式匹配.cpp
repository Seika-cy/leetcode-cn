/*
 * @lc app=leetcode.cn id=10 lang=cpp
 *
 * [10] 正则表达式匹配
 */

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
 public:
  bool isMatch(string s, string p) {
    auto len1 = s.size(), len2 = p.size();
    vector<vector<bool>> dp(len1 + 1, vector<bool>(len2 + 1, false));
    dp[0][0] = true;
    auto matches = [&](size_t i, size_t j) -> bool {
      if (i == 0) return false;
      return (p[j - 1] == '.' || s[i - 1] == p[j - 1]) ? true : false;
    };
    for (size_t i = 0; i <= len1; i++) {
      for (size_t j = 1; j <= len2; j++) {
        if (p[j - 1] != '*') {
          if (matches(i, j)) {
            dp[i][j] = dp[i - 1][j - 1];
          }
          // else
          //     dp[i][j] = false;
        }

        else  // when p[j-1]=='*', j>=2
        {
          if (matches(i, j - 1))
            dp[i][j] = dp[i - 1][j] | dp[i][j - 2];
          else
            dp[i][j] = dp[i][j - 2];
        }
      }
    }

#if 0
        for (auto i : dp)
        {
            for (auto j : i)
            {
                cout << j << " ";
            }
            cout << endl;
        }
#endif

    return dp[len1][len2];
  }
};
// @lc code=end

int main(int argc, char const *argv[]) {
  Solution s;
  cout << (s.isMatch("aaa", "ab*a*c*a") ? "true" : "false") << endl;
  return 0;
}
