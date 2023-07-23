/*
 * @lc app=leetcode.cn id=239 lang=cpp
 *
 * [239] 滑动窗口最大值
 */

#include <algorithm>
#include <deque>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
 public:
  vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    // * 单调队列
    deque<int> deq;
    for (int i = 0; i < k; i++) {
      while (!deq.empty() && nums[deq.back()] <= nums[i]) {
        deq.pop_back();
      }
      deq.push_back(i);
    }

    vector<int> ret;
    ret.push_back(nums[deq.front()]);

    for (int i = k; i < nums.size(); i++) {
      while (!deq.empty() && nums[deq.back()] <= nums[i]) {
        deq.pop_back();
      }
      deq.push_back(i);
      
      while (deq.front() <= i - k) {
        deq.pop_front();
      }

      ret.push_back(nums[deq.front()]);
    }

    return ret;
  }
};
// @lc code=end

int main(int argc, char const* argv[]) {
  Solution s;
  vector<int> nums{1, 3, -1, -3, 5, 3, 6, 7};
  int k = 3;
  s.maxSlidingWindow(nums, k);
  return 0;
}
