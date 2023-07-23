/*
 * @lc app=leetcode.cn id=18 lang=cpp
 *
 * [18] 四数之和
 */

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
 public:
  vector<vector<int>> fourSum(vector<int> &nums, int target) {
    auto len = nums.size();
    if (len < 4) return {};
    sort(nums.begin(), nums.end());
    vector<vector<int>> ret;
    
    for (size_t i = 0; i < len - 3; i++) {
      if (i && nums[i] == nums[i - 1]) {
        continue;
      }
      for (size_t j = len - 1; j >= 0; j--) {
        if (i >= j) {
          break;
        }
        if (j != len - 1 && nums[j] == nums[j + 1]) {
          continue;
        }
        int left = i + 1, right = j - 1;
        while (left < right) {
          auto sum = static_cast<long long>(nums[i]) + nums[left] +
                     nums[right] + nums[j];

          if (sum == target) {
            ret.push_back({nums[i], nums[left], nums[right], nums[j]});
            while (left < right && nums[left] == nums[left + 1]) {
              left++;
            }
            while (left < right && nums[right] == nums[right - 1]) {
              right--;
            }
            left++;
            right--;
          } else if (sum > target)
            right--;
          else
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
  vector<int> t = {1000000000, 1000000000, 1000000000, 1000000000};
  for (auto &vec : s.fourSum(t, 0)) {
    for (auto &var : vec) std::cout << var << " ";
    cout << endl;
  }

  return 0;
}
