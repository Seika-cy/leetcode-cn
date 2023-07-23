/*
 * @lc app=leetcode.cn id=226 lang=cpp
 *
 * [226] 翻转二叉树
 */

#include <algorithm>
#include <iostream>
#include <stack>
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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
 public:
  TreeNode *invertTree(TreeNode *root) {
    stack<TreeNode *> st;
    if (root == nullptr) {
      return nullptr;
    } else {
      st.push(root);
    }

    while (!st.empty()) {
      auto node = st.top();
      st.pop();
      std::swap(node->left, node->right);
      if (node->right != nullptr) {
        st.push(node->right);
      }
      if (node->left != nullptr) {
        st.push(node->left);
      }
    }
    return root;
  }
};
// @lc code=end

int main(int argc, char const *argv[]) {
  Solution s;
  // cout << s << endl;
  return 0;
}
