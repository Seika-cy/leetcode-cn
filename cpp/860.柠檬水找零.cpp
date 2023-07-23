/*
 * @lc app=leetcode.cn id=860 lang=cpp
 *
 * [860] 柠檬水找零
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
  bool lemonadeChange(vector<int>& bills) {
    unordered_map<int, int> cashier;
    cashier[5] = 0;
    cashier[10] = 0;
    cashier[20] = 0;

    auto change = [&cashier](int bill) -> bool {
      switch (bill) {
        case 20:
          if (cashier[10] >= 1 && cashier[5] >= 1) {
            --cashier[10];
            --cashier[5];
            ++cashier[20];
            return true;
          } else if (cashier[5] >= 3) {
            cashier[5] -= 3;
            ++cashier[20];
            return true;
          } else {
            return false;
          }

        case 10:
          if (cashier[5] >= 1) {
            --cashier[5];
            ++cashier[10];
            return true;
          } else {
            return false;
          }
          
        case 5:
          ++cashier[5];
          return true;
        default:
          return false;
      }
    };

    for (const auto& bill : bills) {
      if (!change(bill)) {
        return false;
      }
    }
    return true;
  }
};
// @lc code=end

int main(int argc, char const* argv[]) {
  Solution s;
  // cout << s << endl;
  return 0;
}
