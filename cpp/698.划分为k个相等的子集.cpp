/*
 * @lc app=leetcode.cn id=698 lang=cpp
 *
 * [698] 划分为k个相等的子集
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
  bool canPartitionKSubsets(vector<int> &nums, int k) {
    if (nums.size() < k) return false;
    int sum = accumulate(nums.begin(), nums.end(), 0);
    if (sum % k != 0) return false;
    int target = sum / k;
    for (auto &i : nums) {
      if (i > target) return false;
    }

    vector<int> vec(k, 0);
    sort(nums.rbegin(), nums.rend());
    auto dfs = [&, end = nums.cend()](auto &&dfs, auto &&it) {
      if (it == end) return true;
      for (size_t i = 0; i < k; i++) {
        if (vec[i] + *it > target || (i && vec[i - 1] == vec[i])) continue;
        vec[i] += *it;
        if (dfs(dfs, it + 1)) return true;
        vec[i] -= *it;
      }
      return false;
    };
    return nums[0] <= target && dfs(dfs, nums.cbegin());
  }
};
// @lc code=end

int main(int argc, char const *argv[]) {
  Solution s;
  // std::cout<<s<<std::endl;
  return 0;
}
