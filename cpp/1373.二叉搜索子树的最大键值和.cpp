/*
 * @lc app=leetcode.cn id=1373 lang=cpp
 *
 * [1373] 二叉搜索子树的最大键值和
 */

#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};
// @lc code=start

class Solution {
 public:
  struct Nodeinfo {
    bool isBst;
    int min_val, max_val;
    int sum_val;
    Nodeinfo(bool isBst, int min_val, int max_val, int sum_val)
        : isBst(isBst), min_val(min_val), max_val(max_val), sum_val(sum_val){};
  };
  int ans;
  Nodeinfo dfs(TreeNode *t) {
    if (t == nullptr) {
      return Nodeinfo(true, INT32_MAX, INT32_MIN, 0);
    }
    auto left_info = dfs(t->left);
    auto right_info = dfs(t->right);
    if (left_info.isBst && right_info.isBst && t->val > left_info.max_val &&
        t->val < right_info.min_val) {
      int sum = t->val + left_info.sum_val + right_info.sum_val;
      ans = max(ans, sum);
      return Nodeinfo(true, min(left_info.min_val, t->val),
                      max(right_info.max_val, t->val), sum);
    } else
      return Nodeinfo(false, 0, 0, 0);
  }
  int maxSumBST(TreeNode *root) {
    ans = 0;
    dfs(root);
    return ans;
  }
};
// @lc code=end

int main(int argc, char const *argv[]) {
  Solution s;
  // cout << s << endl;
  return 0;
}
