/*
 * @lc app=leetcode.cn id=16 lang=cpp
 *
 * [16] 最接近的三数之和
 */

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
 public:
  int threeSumClosest(vector<int> &nums, int target) {
    auto len = nums.size();
    sort(nums.begin(), nums.end());
    int ret = nums[0] + nums[1] + nums[2];
    for (size_t i = 0; i < len - 2; i++) {
      // * 去重
      if (i && nums[i] == nums[i - 1]) continue;

      int left = i + 1, right = len - 1;

      while (left < right) {
        int sum = nums[i] + nums[left] + nums[right];
        if (sum > target) {
          ret = abs(ret - target) < abs(sum - target) ? ret : sum;
          right--;
        }

        else if (sum < target) {
          ret = abs(ret - target) < abs(sum - target) ? ret : sum;
          left++;
        } else
          return target;
      }
    }
    return ret;
  }
};
// @lc code=end

int main(int argc, char const *argv[]) {
  Solution s;
  vector<int> t{4, 0, 5, -5, 3, 3, 0, -4, -5};
  cout << s.threeSumClosest(t, -2) << endl;
  return 0;
}
