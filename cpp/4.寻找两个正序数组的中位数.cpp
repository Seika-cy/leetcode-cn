/*
 * @lc app=leetcode.cn id=4 lang=cpp
 *
 * [4] 寻找两个正序数组的中位数
 */

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
 public:
  double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
    auto len1 = nums1.size(), len2 = nums2.size();
    bool flag_even = false;
    if ((len1 + len2) % 2 == 0) flag_even = true;
    int n = (len1 + len2) / 2;
    double res = 0;
    int i = 0, j = 0;
    if (flag_even) {
      n--;
      while (n--) {
        if (i == len1)
          j++;
        else if (j == len2)
          i++;
        else if (nums1[i] < nums2[j])
          i++;
        else
          j++;
      }
      int t = 2;
      while (t--) {
        if (i == len1) {
          res += nums2[j];
          j++;
        } else if (j == len2) {
          res += nums1[i];
          i++;
        } else if (nums1[i] < nums2[j]) {
          res += nums1[i];
          i++;
        } else {
          res += nums2[j];
          j++;
        }
      }
      res /= 2;
    } else {
      while (n--) {
        if (i == len1)
          j++;
        else if (j == len2)
          i++;
        else if (nums1[i] < nums2[j])
          i++;
        else
          j++;
      }
      int t = 1;
      while (t--) {
        if (i == len1) {
          res += nums2[j];
          j++;
        } else if (j == len2) {
          res += nums1[i];
          i++;
        } else if (nums1[i] < nums2[j]) {
          res += nums1[i];
          i++;
        } else {
          res += nums2[j];
          j++;
        }
      }
    }
    return res;
  }
};
// @lc code=end

int main(int argc, char const *argv[]) {
  Solution s;
  // cout << s.findMedianSortedArrays({1, 2}, {3, 4}) << endl;
  return 0;
}
