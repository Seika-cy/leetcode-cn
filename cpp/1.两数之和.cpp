/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
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
  vector<int> twoSum(vector<int> &nums, int target) {
    unordered_map<int, int> record;
    for (int i = 0; i < nums.size(); i++) {
      if (record.count(nums[i]) > 0) return {record[nums[i]], i};
      record[target - nums[i]] = i;
    }
    return {};
  }
};
// @lc code=end

int main(int argc, char const *argv[]) {
  Solution s;
  // std::cout<<s<<std::endl;
  return 0;
}
