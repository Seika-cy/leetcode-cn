/*
 * @lc app=leetcode.cn id=11 lang=cpp
 *
 * [11] 盛最多水的容器
 */

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
 public:
  int maxArea(vector<int> &height) {
    int left = 0, right = height.size() - 1;
    int minval_index, v, v_max = 0;

    do {
      minval_index = height[left] < height[right] ? left : right;
      v = (right - left) * height[minval_index];
      v_max = max(v, v_max);
      if (minval_index == left)
        left++;
      else if (minval_index == right)
        right--;
    } while (left < right);

    return v_max;
  }
};
// @lc code=end

int main(int argc, char const *argv[]) {
  Solution s;
  // std::cout<<s<<std::endl;
  return 0;
}
