/*
 * @lc app=leetcode.cn id=13 lang=cpp
 *
 * [13] 罗马数字转整数
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
  int romanToInt(string s) {
    unordered_map<char, int> dict = {{'I', 1},   {'V', 5},   {'X', 10},
                                     {'L', 50},  {'C', 100}, {'D', 500},
                                     {'M', 1000}};
    int sum = 0;
    for (size_t i = 0; i < s.size() - 1; i++) {
      if (dict.at(s[i]) - dict.at(s[i + 1]) < 0)
        sum -= dict.at(s[i]);
      else
        sum += dict.at(s[i]);
    }
    sum += dict.at(s.back());

    return sum;
  }
};
// @lc code=end

int main(int argc, char const *argv[]) {
  Solution s;
  cout << s.romanToInt("MCMXCIV") << endl;
  return 0;
}
