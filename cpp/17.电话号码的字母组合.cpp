/*
 * @lc app=leetcode.cn id=17 lang=cpp
 *
 * [17] 电话号码的字母组合
 */

#include <algorithm>
#include <array>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
 public:
  vector<string> letterCombinations(string digits) {
    if (digits.size() == 0) return {};
    array<string, 8> arr = {"abc", "def",  "ghi", "jkl",
                            "mno", "pqrs", "tuv", "wxyz"};
    int n = 1;
    int t = 1;
    for (auto &digit : digits) n *= arr[digit - '2'].size();
    vector<string> ret(n, "");
    for (size_t i = 0; i < digits.size(); i++) {
      int cur = 0;
      auto &str = arr[digits[i] - '2'];
      int j = t;
      t *= str.size();
      while (j--) {
        for (size_t k = 0; k < str.size(); k++) {
          for (size_t l = 0; l < n / t; l++) ret[cur++].push_back(str[k]);
        }
      }
    }

    return ret;
  }
};
// @lc code=end

int main(int argc, char const *argv[]) {
  Solution s;
  for (auto &str : s.letterCombinations("23")) {
    cout << str << " ";
  }
  cout << endl;
  return 0;
}
