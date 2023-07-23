/*
 * @lc app=leetcode.cn id=80 lang=cpp
 *
 * [80] 删除有序数组中的重复项 II
 */

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
 public:
  int removeDuplicates(vector<int>& nums) {
    int cnt = 0;
    bool flag = 0;
    for (int i = 0; i < nums.size(); i++) {
      if (i && nums[i] == nums[i - 1]) {
        if (flag) {
          cnt++;
        } else {
          flag = 1;
        }
      } else {
        flag = 0;
      }
      nums[i - cnt] = nums[i];
    }
    return nums.size() - cnt;
  }
};
// @lc code=end

int main(int argc, char const* argv[]) {
  Solution s;
  // cout << s << endl;
  return 0;
}
