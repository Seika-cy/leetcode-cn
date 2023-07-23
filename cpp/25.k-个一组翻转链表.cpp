/*
 * @lc app=leetcode.cn id=25 lang=cpp
 *
 * [25] K 个一组翻转链表
 */

#include <iostream>
#include <utility>
#include <vector>
struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};
using namespace std;
// @lc code=start
class Solution {
 public:
  ListNode* reverseKGroup(ListNode* list, int k) {
    if (k == 1) return list;
    //* 用头插法将从lptr开的的k个node倒置，并返回新建链表的头尾
    auto func = [](ListNode* lptr, int k) -> pair<ListNode*, ListNode*> {
      auto head = ListNode();
      auto ptr = lptr;
      int n = k;
      while (n--) {
        auto t = head.next;
        head.next = ptr;
        ptr = ptr->next;
        head.next->next = t;
      }
      auto right = lptr;
      auto left = head.next;
      return {left, right};
    };
    ListNode head(0, list);
    auto ptr = list;
    int cnt = 0;

    ListNode* lpre = &head;
    ListNode* lptr = nullptr;
    ListNode* rptr = nullptr;
    ListNode* rpos = nullptr;
    while (ptr != nullptr) {
      if (cnt == 0) {
        lptr = ptr;
      } else if (cnt == k - 1) {
        rpos = ptr->next;
        auto pr = func(lptr, k);
        lptr = pr.first, rptr = pr.second;
        lpre->next = lptr, rptr->next = rpos;
        ptr = rptr;
        lpre = ptr;
      }
      ptr = ptr->next;
      cnt++;
      cnt %= k;
    }
    return head.next;
  }
};
// @lc code=end

int main(int argc, char const* argv[]) {
  Solution s;
  vector<int> vec{1, 2, 3, 4, 5};
  auto head = new ListNode();
  auto ptr = head;
  for (auto i : vec) {
    auto base = new ListNode(i);
    ptr->next = base;
    ptr = ptr->next;
  }
  ptr = s.reverseKGroup(head->next, 2);
  while (ptr != nullptr) {
    std::cout << ptr->val << " ";
    ptr = ptr->next;
  }
  std::cout << "" << std::endl;
  return 0;
}