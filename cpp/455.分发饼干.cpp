/*
 * @lc app=leetcode.cn id=455 lang=cpp
 *
 * [455] 分发饼干
 */

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
 public:
  int findContentChildren(vector<int>& g, vector<int>& s) {
    std::sort(g.rbegin(), g.rend());
    std::sort(s.rbegin(), s.rend());
    int i = 0, j = 0;
    int cnt = 0;
    while (i < g.size() && j < s.size()) {
      if (g[i] <= s[j]) {
        i++;
        j++;
        cnt++;
      } else {
        i++;
      }
    }
    return cnt;
  }
};
// @lc code=end

int main(int argc, char const* argv[]) {
  Solution s;
  // cout << s << endl;
  return 0;
}
