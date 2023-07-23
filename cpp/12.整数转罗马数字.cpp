/*
 * @lc app=leetcode.cn id=12 lang=cpp
 *
 * [12] 整数转罗马数字
 */

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
 public:
  string intToRoman(int num) {
    vector<int> vec(7, 0);
    auto func = [&](auto i, auto n) {
      vec[i] = num / n;
      num %= n;
    };
    int arr[] = {1000, 500, 100, 50, 10, 5, 1};
    string dict = "MDCLXVI";
    for (size_t i = 0; i < 7; i++) func(i, arr[i]);
    string str;
    for (size_t i = 0; i < 7; i++) {
      if (i == 1 || i == 3 || i == 5) {
        if (vec[i] == 1 && vec[i + 1] == 4) {
          str += dict[i + 1];
          str += dict[i - 1];
          i++;
          continue;
        } else if (vec[i] == 0 && vec[i + 1] == 4) {
          str += dict[i + 1];
          str += dict[i];
          i++;
          continue;
        }
      }
      int n = vec[i];
      while (n--) str += dict[i];
    }
    return str;
  }
};
// @lc code=end

int main(int argc, char const *argv[]) {
  Solution s;
  cout << s.intToRoman(1994) << endl;
  return 0;
}
