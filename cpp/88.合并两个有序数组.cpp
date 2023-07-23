/*
 * @lc app=leetcode.cn id=88 lang=cpp
 *
 * [88] 合并两个有序数组
 */

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
 public:
  void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int i = 0, j = 0;
    vector<int> vec;
    vec.reserve(m + n);

    while (i < m && j < n) {
      if (nums1[i] < nums2[j]) {
        vec.push_back(nums1[i]);
        i++;
      } else {
        vec.push_back(nums2[j]);
        j++;
      }
    }

    if (i == m) {
      while (j < n) {
        vec.push_back(nums2[j]);
        j++;
      }
    } else {
      while (i < m) {
        vec.push_back(nums1[i]);
        i++;
      }
    }
    nums1 = std::move(vec);
  }
};
// @lc code=end

int main(int argc, char const* argv[]) {
  Solution s;
  // cout << s << endl;
  return 0;
}
