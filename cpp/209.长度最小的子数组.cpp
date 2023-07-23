/*
 * @lc app=leetcode.cn id=209 lang=cpp
 *
 * [209] 长度最小的子数组
 */

#include <algorithm>
#include <cstdint>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
 public:
  int minSubArrayLen(int target, vector<int>& nums) {
    int left = 0;
    int right = 0;
    int sum = 0;
    int min_len = INT32_MAX;

    while (1) {
      if (sum < target) {
        if (right != nums.size()) {
          sum += nums[right];
          right++;
        } else {
          break;
        }
      } else {
        min_len = std::min(min_len, (right - left));
        sum -= nums[left];
        left++;
      }
    }
    return min_len == INT32_MAX ? 0 : min_len;
  }
};
// @lc code=end

int main(int argc, char const* argv[]) {
  Solution s;
  // cout << s << endl;
  return 0;
}
