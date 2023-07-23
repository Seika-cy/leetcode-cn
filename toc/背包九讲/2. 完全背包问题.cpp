/*
 *有N件物品和一个最多能背重量为W的背包。第i件物品的重量是weight[i]，得到的价值是value[i]
 *。
 *每件物品都有无限个（也就是可以放入背包多次），求解将哪些物品装入背包里物品价值总和最大。
 *完全背包和01背包问题唯一不同的地方就是，每种物品有无限件。
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  int func(const vector<int> &weigth, const vector<int> &value,
           const int bagweigth) {
    //! T(O) = (nv^2),复杂度太高
    auto func1 = [&]() {
      int n = weigth.size();
      vector<vector<int>> dp(n, vector<int>(bagweigth + 1, 0));
      for (int j = weigth[0]; j <= bagweigth; j++) {
        dp[0][j] = value[0] * (j / weigth[0]);
      }
      for (int i = 1; i < n; i++) {
        for (int j = 1; j <= bagweigth; j++) {
          for (int k = 0; k <= j / weigth[i]; k++) {
            dp[i][j] = max(
                dp[i][j],
                max(dp[i - 1][j], dp[i - 1][j - weigth[i] * k] + k * value[i]));
          }
        }
      }
      return dp[n - 1][bagweigth];
    };

    auto func2 = [&]() {
      vector<int> weigth_01, value_01;
      auto convert01 = [&] {
        for (int i = 0; i < weigth.size(); i++) {
          for (int j = 1; j * weigth[i] <= bagweigth; j *= 2) {
            weigth_01.push_back(weigth[i] * j);
            value_01.push_back(value[i] * j);
          }
        }
      };
      convert01();
      int n = weigth_01.size();
      vector<vector<int>> dp(n, vector<int>(bagweigth + 1, 0));
      for (int j = weigth_01[0]; j <= bagweigth; j++) {
        dp[0][j] = value_01[0];
      }
      for (int i = 1; i < n; i++) {
        for (int j = 0; j <= bagweigth; j++) {
          if (j < weigth_01[i])
            dp[i][j] = dp[i - 1][j];
          else
            dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weigth_01[i]] + value_01[i]);
        }
      }
      return dp[n - 1][bagweigth];
    };
    return func2();
  }
};

int main(int argc, char const *argv[]) {
  Solution s;

#if 1
  int n, m;
  cin >> n >> m;
  vector<int> weigth(n), value(n);
  for (int i = 0; i < n; i++) {
    cin >> weigth[i] >> value[i];
  }
  cout << s.func(weigth, value, m) << endl;
#endif

#if 0
  vector<int> weigth{1, 2, 3, 4};
  vector<int> value{2, 4, 4, 5};
  int bagweigth = 5;
  cout << s.func(weigth, value, bagweigth) << endl;
#endif
}
