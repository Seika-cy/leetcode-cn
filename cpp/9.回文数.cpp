/*
 * @lc app=leetcode.cn id=9 lang=cpp
 *
 * [9] 回文数
 */

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
 public:
  bool isPalindrome(int x) {
    if (x < 0) return false;

    string str = to_string(x);
    reverse(str.begin(), str.end());
    int rev_x = 0;
    try {
      rev_x = stoi(str);
    } catch (const out_of_range &e) {
      return false;
    }
    if (rev_x == x)
      return true;
    else
      return false;
  }
};
// @lc code=end

int main(int argc, char const *argv[]) {
  Solution s;
  cout << s.isPalindrome(121) << endl;
  return 0;
}
