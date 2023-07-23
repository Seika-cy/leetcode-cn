/*
 * @lc app=leetcode.cn id=121 lang=cpp
 *
 * [121] 买卖股票的最佳时机
 */

#include <algorithm>
#include <cstdint>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
 public:
  int maxProfit(vector<int>& prices) {
    int min_price = INT32_MAX;
    int profit = 0;
    for (const auto& price : prices) {
      profit = std::max(profit, price - min_price);
      min_price = std::min(min_price, price);
    }
    return profit;
  }
};
// @lc code=end

int main(int argc, char const* argv[]) {
  Solution s;
  // cout << s << endl;
  return 0;
}
