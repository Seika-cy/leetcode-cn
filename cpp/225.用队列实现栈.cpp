/*
 * @lc app=leetcode.cn id=225 lang=cpp
 *
 * [225] 用队列实现栈
 */

#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;
// @lc code=start
class MyStack {
 public:
  MyStack() {}

  void push(int x) {
    int n = queue_.size();
    queue_.push(x);
    while(n--) {
        queue_.push(queue_.front());
        queue_.pop();
    }
  }

  int pop() {
    auto ret = queue_.front();
    queue_.pop();
    return ret;
  }

  int top() { return queue_.front(); }

  bool empty() { return queue_.empty(); }

 private:
  queue<int> queue_;
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
// @lc code=end

int main(int argc, char const *argv[]) {
  // Solution s;
  // cout << s << endl;
  return 0;
}
