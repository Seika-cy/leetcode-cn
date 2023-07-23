/*
 * @lc app=leetcode.cn id=1079 lang=cpp
 *
 * [1079] 活字印刷
 */

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <array>
using namespace std;
// @lc code=start
class Solution {
 public:
  int numTilePossibilities(string tiles) {
    array<int, 26> record = {0};
    for(auto &ch : tiles)
        record[ch-'A']++;
    vector <int> vec;
    for(auto &item : record)
        if(item)
            vec.push_back(item);
    sort(vec.begin(),vec.end());

  }
};
// @lc code=end

int main(int argc, char const *argv[]) {
  Solution s;
  // cout << s << endl;
  return 0;
}
