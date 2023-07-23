/*
 * @lc app=leetcode.cn id=24 lang=cpp
 *
 * [24] 两两交换链表中的节点
 */

#include <pthread.h>
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
  ListNode *swapPairs(ListNode *l) {
    ListNode head(0, l);
    auto pre = &head;
    auto ptr = pre->next;
    while (ptr != nullptr && ptr->next != nullptr) {
      auto t = ptr->next->next;
      pre->next = ptr->next;
      ptr->next->next = ptr;
      ptr->next = t;
    
      pre = ptr;
      ptr = ptr->next;
    }

    return head.next;
  }
};
// @lc code=end

int main(int argc, char const *argv[]) {
  Solution s;
  // cout << s << endl;
  return 0;
}
