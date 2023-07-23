/*
 * @lc app=leetcode.cn id=1005 lang=cpp
 *
 * [1005] K 次取反后最大化的数组和
 */

#include <algorithm>
#include <cmath>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
 public:
  int largestSumAfterKNegations(vector<int>& nums, int k) {
    std::sort(nums.begin(), nums.end());
    int sum = std::accumulate(nums.cbegin(), nums.cend(), 0);

    int negative_number =
        std::find_if(nums.cbegin(), nums.cend(),
                     [](const int& val) -> bool { return val >= 0; }) -
        nums.cbegin();

    auto min_abs_it = std::min_element(
        nums.cbegin(), nums .cend(), [](const int& lhs, const int& rhs) -> bool {
          return std::abs(lhs) < std::abs(rhs);
        });

    if (k <= negative_number) {
      for (int i = 0; i < k; i++) {
        sum -= nums[i] * 2;
      }
    } else {
      for (int i = 0; i < negative_number; i++) {
        sum -= nums[i] * 2;
      }
      if ((k - negative_number) % 2 == 1) {
        sum -= std::abs(*min_abs_it) * 2;
      }
    }
    return sum;
  }
};
// @lc code=end

int main(int argc, char const* argv[]) {
  Solution s;
  // cout << s << endl;
  return 0;
}
