#include <functional>
#include <iostream>

void move(int low, int high, char from, char buffer, char to) {
  static int cnt = 0;
  if (low == high) {
    cnt++;
    std::cout << "Step " << cnt << ": move " << low << " from " << from
              << " to " << to << std::endl;
  }

  else {
    move(low + 1, high, from, to, buffer);
    move(low, low, from, buffer, to);
    move(low + 1, high, buffer, from, to);
  }
}
int main(int argc, char const *argv[]) {
  int n = 6;
  move(1, n, 'a', 'b', 'c');
  return 0;
}
