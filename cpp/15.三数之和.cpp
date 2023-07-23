/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 */

#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
 public:
  vector<vector<int>> threeSum(vector<int> &nums) {
    vector<vector<int>> ret;
    auto len = nums.size();
    // if (len < 3)
    //     return ret;
    sort(nums.begin(), nums.end());
    for (size_t i = 0; i < len - 2; i++) {
      if (nums[i] > 0) {
        return ret;
      }

      // * 去重
      if (i && nums[i] == nums[i - 1]) {
        continue;
      }

      int left = i + 1, right = len - 1;

      while (left < right) {
        if (nums[i] + nums[left] + nums[right] > 0) {
          right--;
        } else if (nums[i] + nums[left] + nums[right] < 0) {
          left++;
        } else {
          ret.push_back({nums[i], nums[left], nums[right]});

          // * 去重
          while (left < right && nums[right] == nums[right - 1]) right--;
          while (left < right && nums[left] == nums[left + 1]) left++;
          right--;
          left++;
        }
      }
    }
    return ret;
  }
};
// @lc code=end

int main(int argc, char const *argv[]) {
  Solution s;
  // cout << s << endl;
  return 0;
}
