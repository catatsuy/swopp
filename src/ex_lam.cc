#include <functional>

int main() {
  int a = 2;
  int b = 3;
  std::function<int ()> Sum =
      [=](int x, int y) { return x + y; };
  int c = Sum(a, b);
  return 0;
}
