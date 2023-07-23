/*
 * 奇怪的电梯 C++ bfs
 * https://www.luogu.com.cn/problem/P1135
 */
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main(int argc, char const *argv[]) {
  int n, a, b;
  cin >> n >> a >> b;
  vector<int> vec(n);
  for (int i = 0; i < n; i++) cin >> vec[i];

  auto bfs = [&]() {
    queue<int> buf;
    vector<bool> rd(n, false);  //* 记录该层是否被访问过，默认为否
    int level = 0;  //* level 表示树节点所在层级，即按按钮次数
    buf.push(a);
    buf.push(-1);  //! 用-1表示二叉树的层结束的标志,按钮次数相同的为同一层
    rd[a - 1] = true;
    while (!buf.empty()) {
      auto t = buf.front();
      buf.pop();

      if (t == -1)  //* 树分层判断
      {
        level++;
        if (!buf.empty())  //* 防止队列中只剩-1时，无限循环
          buf.push(-1);
        continue;
      }
      if (t == b)
        return level;
      else {
        int t1 = t - vec[t - 1],  // 按上后的层数
            t2 = t + vec[t - 1];  // 按下后的层数
        if (t1 >= 1 && !rd[t1 - 1])
        //* 若该层可到达，且没有被访问过
        {
          buf.push(t1);
          rd[t1 - 1] = true;
        }

        if (t2 <= n && !rd[t2 - 1]) {
          buf.push(t2);
          rd[t2 - 1] = true;
        }
      }
    }  // *循环正常结束，目标不可达
    return -1;
  };
  cout << bfs() << endl;
  return 0;
}
