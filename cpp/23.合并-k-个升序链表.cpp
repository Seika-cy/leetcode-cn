/*
 * @lc app=leetcode.cn id=23 lang=cpp
 *
 * [23] 合并 K 个升序链表
 */

#include <iostream>
#include <map>
#include <queue>
#include <utility>
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
  ListNode *mergeKLists(vector<ListNode *> &lists) {
    auto cmp = [](const pair<int, ListNode *> &left,
                  const pair<int, ListNode *> &right) {
      return left.first > right.first;
    };
    priority_queue<pair<int, ListNode *>, vector<pair<int, ListNode *> >,
                   decltype(cmp)>
        record(cmp);

    for (auto list : lists) {
      if (list != nullptr) {
        record.push(make_pair(list->val, list));
      }
    }

    if (record.empty()) {
      return nullptr;
    }

    struct ListNode head;
    auto *ptr = &head;

    while (!record.empty()) {
      auto front = record.top();
      record.pop();

      ptr->next = front.second;
      ptr = ptr->next;

      auto t = front.second->next;
      if (t != nullptr) {
        record.push(make_pair(t->val, t));
      }
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
