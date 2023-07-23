/*
 * @lc app=leetcode.cn id=26 lang=cpp
 *
 * [26] 删除有序数组中的重复项
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
    for (int i = 0; i < nums.size(); i++) {
      if (i && nums[i] == nums[i - 1]) {
        cnt++;
      }
      nums[i - cnt] = nums[i];
    }
    return (nums.size() - cnt);
  }
};
// @lc code=end

int main(int argc, char const* argv[]) {
  Solution s;
  // cout << s << endl;
  return 0;
}
