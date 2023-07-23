/*
 * @lc app=leetcode.cn id=44 lang=cpp
 *
 * [44] 通配符匹配
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
      return (p[j - 1] == '?' || s[i - 1] == p[j - 1]) ? true : false;
    };

    for (size_t j = 1; j <= len2; j++) {
      if (p[j - 1] == '*')
        dp[0][j] = true;
      else
        break;
    }

    for (size_t i = 1; i <= len1; i++) {
      for (size_t j = 1; j <= len2; j++) {
        if (p[j - 1] == '*')  // i>=1,j>=1
        {
          dp[i][j] = dp[i - 1][j] | dp[i][j - 1];
        }

        else {
          if (matches(i, j)) {
            dp[i][j] = dp[i - 1][j - 1];
          }
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
  cout << s.isMatch("aa", "*") << endl;
  return 0;
}
