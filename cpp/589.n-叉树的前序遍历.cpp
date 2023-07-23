/*
 * @lc app=leetcode.cn id=589 lang=cpp
 *
 * [589] N 叉树的前序遍历
 */

#include <algorithm>
#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;
class Node {
 public:
  int val;
  vector<Node*> children;

  Node() {}

  Node(int _val) { val = _val; }

  Node(int _val, vector<Node*> _children) {
    val = _val;
    children = _children;
  }
};
// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
 public:
  vector<int> preorder(Node* root) {
    stack<Node*> st;
    if (root == nullptr) {
      st.push(root);
    } else {
      return {};
    }

    vector<int> ret;
    while (!st.empty()) {
      auto node = st.top();
      st.pop();
      
      if (node != nullptr) {
        auto children = node->children;
        for (int i = children.size() - 1; i >= 0; i--) {
          if (children[i] != nullptr) {
            st.push(children[i]);
          }
        }
        st.push(node);
        st.push(nullptr);
      } else {
        node = st.top();
        st.pop();
        ret.push_back(node->val);
        std::cout << node->val << std::endl;
      }
    }
    return ret;
  }
};
// @lc code=end

int main(int argc, char const* argv[]) {
  Solution s;
  // cout << s << endl;
  return 0;
}
