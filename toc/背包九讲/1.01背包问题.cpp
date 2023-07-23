/*
 * 有 n 件物品和一个容量为 v 的背包。第i件物品的费用是 c[i] ，价值是 w[i] 。
 * 每件物品只能用一次,求解将哪些物品装入背包可使这些
 * 物品的费用总和不超过背包容量，且价值总和最大。
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  int func(vector<int> &weigth, vector<int> &value, int bagweigth) {
    int n = weigth.size();
    //! dp[i][j]表示前i件物品恰放入一个容量为j的背包可以获得的最大价值
    vector<vector<int>> dp(n, vector<int>(bagweigth + 1, 0));
    for (int j = weigth[0]; j <= bagweigth; j++) {
      dp[0][j] = value[0];
    }
    for (int i = 1; i < n; i++) {
      for (int j = 0; j <= bagweigth; j++) {
        if (j < weigth[i])
          dp[i][j] = dp[i - 1][j];
        else
          dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weigth[i]] + value[i]);
      }
    }

#if 0
        cout << n << " " << bagweigth << endl;
        for (auto i : dp)
        {
            for (auto j : i)
            {
                cout << j << " ";
            }
            cout << endl;
        }
#endif
    return dp[n - 1][bagweigth];
  }
};

int main(int argc, char const *argv[]) {
  Solution s;
#if 0
    int n, m;
    vector<int> w, v;
    cin >> n >> m;
    while (n--)
    {
        int t1, t2;
        cin >> t1 >> t2;
        w.emplace_back(t1);
        v.emplace_back(t2);
    }
    cout << s.func(w, v, m) << endl;
#endif

  vector<int> w{15, 20, 30};
  vector<int> v{1, 3, 4};
  cout << s.func(w, v, 4) << endl;
  return 0;
}
