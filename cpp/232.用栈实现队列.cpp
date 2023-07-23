/*
 * @lc app=leetcode.cn id=232 lang=cpp
 *
 * [232] 用栈实现队列
 */

#include <algorithm>
#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;

// @lc code=start
class MyQueue {
 public:
  MyQueue() {}

  void push(int x) { instack_.push(x); }

  int pop() {
    if (outstack_.empty()) {
      in2out();
    }
    auto ret = outstack_.top();
    outstack_.pop();
    return ret;
  }

  int peek() {
    if (outstack_.empty()) {
      in2out();
    }
    return outstack_.top();
  }

  bool empty() { return instack_.empty() && outstack_.empty(); }

 private:
  stack<int> instack_, outstack_;

  void in2out() {
    while (!instack_.empty()) {
      outstack_.push(instack_.top());
      instack_.pop();
    }
  }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
// @lc code=end

int main(int argc, char const *argv[]) {
  // Solution s;
  // cout << s << endl;
  return 0;
}
