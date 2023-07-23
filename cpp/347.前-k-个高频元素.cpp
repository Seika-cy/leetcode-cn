/*
 * @lc app=leetcode.cn id=347 lang=cpp
 *
 * [347] 前 K 个高频元素
 */

#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
 public:
  vector<int> topKFrequent(vector<int> &nums, int k) {
    unordered_map<int, int> rd;
    for (auto &n : nums) {
      rd[n]++;
    }

    priority_queue<std::pair<int, int>, vector<std::pair<int, int>>, Cmp> heap;

    for (const auto &item : rd) {
      heap.push(item);
      if (heap.size() > k) {
        heap.pop();
      }
    }

    vector<int> ret(k);
    for (int i = k - 1; i >= 0; i--) {
      ret[i] = heap.top().first;
      heap.pop();
    }
    return ret;
  }

 private:
  struct Cmp {
    auto operator()(const pair<int, int> &lhs, const pair<int, int> &rhs)
        -> bool {
      return lhs.second > rhs.second;
    }
  };
};
// @lc code=end

int main(int argc, char const *argv[]) {
  Solution s;
  // cout << s << endl;
  return 0;
}
