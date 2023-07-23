/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] 两数相加
 */

#include <algorithm>
#include <iostream>
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
  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    auto head = new ListNode();
    head->next = l1;
    auto pre = head;
    while (l1 && l2) {
      l1->val += l2->val;
      l1 = l1->next;
      l2 = l2->next;
      pre = pre->next;
    }
    if (l1) pre->next = l1;
    if (l2) pre->next = l2;
    auto ptr = head->next;
    while (ptr) {
      if (ptr->val < 10) {
        ptr = ptr->next;
        continue;
      }

      ptr->val -= 10;
      if (ptr->next)
        (ptr->next->val)++;
      else {
        ptr->next = new ListNode(1);
      }
      ptr = ptr->next;
    }
    ptr = head->next;
    delete head;
    return ptr;
  }
};
// @lc code=end

int main(int argc, char const *argv[]) {
  Solution s;
  // std::cout<<s<<std::endl;
  return 0;
}
