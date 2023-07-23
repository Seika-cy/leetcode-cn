/*
 * @lc app=leetcode.cn id=19 lang=cpp
 *
 * [19] 删除链表的倒数第 N 个结点
 */

#include <algorithm>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};
// @lc code=start
class Solution {
 public:
  ListNode *removeNthFromEnd(ListNode *head, int n) {
    auto node = make_unique<ListNode>();
    node->next = head;
    auto ptr = node.get();
    auto probe = ptr;
    while (n--) probe = probe->next;
    while (1) {
      if (probe->next == nullptr) {
        auto t = ptr->next;
        ptr->next = t->next;
        break;
      }
      probe = probe->next;
      ptr = ptr->next;
    }
    return node->next;
  }
};
// @lc code=end

int main(int argc, char const *argv[]) {
  Solution s;
  auto head = new ListNode(0);
  for (size_t i = 4; i > 0; i--) {
    auto node = new ListNode(i);
    node->next = head->next;
    head->next = node;
  }
  auto ptr = s.removeNthFromEnd(head, 2);
  while (ptr) {
    cout << ptr->val << " ";
    ptr = ptr->next;
  }
  cout << endl;
  return 0;
}
