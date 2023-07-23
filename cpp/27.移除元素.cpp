/*
 * @lc app=leetcode.cn id=27 lang=cpp
 *
 * [27] 移除元素
 */

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
 public:
  int removeElement(vector<int>& nums, int val) {
    int cnt = 0;
    for (int i = 0; i < nums.size(); i++) {
      if (nums[i] == val)
        cnt++;
      else
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
