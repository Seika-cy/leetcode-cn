/*
 *  N皇后问题 C++ dfs
 * 在8×8格的国际象棋上摆放八个皇后，使其不能互相攻击，
 * 即任意两个皇后都不能处于同一行、同一列或同一斜线上，
 * 问一共有多少种摆法。
 *
 */

#include <iostream>
#include <vector>

using namespace std;
const int N = 8;

void solveNQueens(vector<vector<bool>> &board, int col) {
  // *判断该点能否放置皇后
  auto isSafe = [&](int row, int col) {
    for (int y = 0; y < col; y++)
      if (board[row][y] == 1) return false;
    for (int x = row, y = col; x >= 0 && y >= 0; x--, y--)
      if (board[x][y] == 1) return false;
    for (int x = row, y = col; x < N && y >= 0; x++, y--)
      if (board[x][y] == 1) return false;
    return true;
  };
  static int cnt = 0;
  if (col == N)  //* 满足n皇后的条件，到达棋盘底部
  {
    cnt++;
    cout << "Case " << cnt << ":" << endl;
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) cout << board[i][j] << " ";
      cout << endl;
    }
    cout << endl;
  }
  for (int i = 0; i < N; i++)  //* 遍历该行
  {
    if (isSafe(i, col)) {
      board[i][col] = 1;
      solveNQueens(board, col + 1);  //* 遍历下一行
      board[i][col] = 0;             //! 回溯
    }
  }
}

int main() {
  vector<vector<bool>> board(N, vector<bool>(N, 0));
  solveNQueens(board, 0);  // dfs
  return 0;
}