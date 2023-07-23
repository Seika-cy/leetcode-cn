/*
 * @lc app=leetcode.cn id=45 lang=cpp
 *
 * [45] 跳跃游戏 II
 */

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
 public:
  int jump(vector<int>& nums) {
    // T = O(n^2)
    // int i = nums.size() - 1;
    // int cnt = 0;
    // int cur = i;
    // while (i) {
    //   for (int j = i - 1; j >= 0; j--) {
    //     int dict = i - j;
    //     if (dict <= nums[j]) cur = j;
    //   }
    //   i = cur;
    //   cnt++;
    // }
    // return cnt;

    int cur = 0;
    int cnt = 0;
    while (cur <= nums.size() - 2) {
      int max_pos = cur, next = cur;
      for (int i = cur + 1; i <= cur + nums[cur] && i < nums.size(); i++) {
        if (nums[i] + i > max_pos) {
          max_pos = nums[i] + i;
          next = i;
        }
      }
      if(max_pos>=nums.size()-2)
        return cnt+2;
      cur = next;
      cnt++;
    }
    return 0;
  }
};
// @lc code=end

int main(int argc, char const* argv[]) {
  Solution s;
  vector<int> vec{2,3,1,1,4};
  cout << s.jump(vec) << endl;
  return 0;
}
