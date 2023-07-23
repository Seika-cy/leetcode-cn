/*
 * @lc app=leetcode.cn id=169 lang=cpp
 *
 * [169] 多数元素
 */

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
 public:
  int majorityElement(vector<int>& nums) {
    int candidate = 0, votes = 0;
    
    for (const auto& n : nums) {
      if (votes == 0) {
        candidate = n;
      }
      if (n == candidate) {
        votes++;
      } else {
        votes--;
      }
    }
    return candidate;
  }
};
// @lc code=end

int main(int argc, char const* argv[]) {
  Solution s;
  // cout << s << endl;
  return 0;
}
