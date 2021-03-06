#include <iostream>

int main ()
{
  double x1, y1, w1, h1;
  std::cin >> x1 >> y1 >> w1 >> h1;

  double x2, y2, w2, h2;
  std::cin >> x2 >> y2 >> w2 >> h2;

  double overlap = (std::min(x1 + w1, x2 + w2) - std::max(x1, x2)) * (std::min(y1 + h1, y2 + h2) - std::max(y1, y2));
  std::cout << overlap << std::endl;

  return 0;
}
