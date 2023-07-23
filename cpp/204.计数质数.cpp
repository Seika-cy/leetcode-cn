/*
 * @lc app=leetcode.cn id=204 lang=cpp
 *
 * [204] 计数质数
 */

#include <iostream>
#include <string>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
 public:
  int countPrimes(int n) {
    vector<bool> isPrime(n + 1, true);
    isPrime[0] = isPrime[1] = false;
    int cnt = 0;
    for (int i = 2; i < n; i++) {
      if (isPrime[i]) {
        cnt++;
        if (static_cast<long long>(i) * i < n)
          for (int j = i * i; j < n; j += i) {
            isPrime[j] = false;
          }
      }
    }
    return cnt;
  }
};
// @lc code=end

int main(int argc, char const *argv[]) {
  Solution s;
  cout << s.countPrimes(499979) << endl;
  
  return 0;
}
