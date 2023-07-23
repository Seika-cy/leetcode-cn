/*
 * @lc app=leetcode.cn id=416 lang=cpp
 *
 * [416] 分割等和子集
 */

#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
 public:
  bool canPartition(vector<int> &nums) {
    if (nums.size() < 2) return false;

    int sum = accumulate(nums.begin(), nums.end(), 0);
    if (sum % 2 != 0) return false;

    int target = sum / 2;
    for (auto &i : nums)
      if (i > target) return false;

    vector<vector<bool>> dp(nums.size(), vector<bool>(target + 1, false));

    dp[0][nums[0]] = true;
    for (size_t i = 0; i < nums.size(); i++) dp[i][0] = true;

    for (size_t i = 1; i < nums.size(); i++) {
      for (size_t j = 0; j <= target; j++) {
        if (j < nums[i])
          dp[i][j] = dp[i - 1][j];
        else
          dp[i][j] = dp[i - 1][j] | dp[i - 1][j - nums[i]];
      }
    }
    return dp[nums.size() - 1][target];
  }
};
// @lc code=end

int main(int argc, char const *argv[]) {
  Solution s;
  // std::cout<<s<<std::endl;
  return 0;
}
