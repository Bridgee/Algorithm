#include <iostream>
#include <ctime>

int get_change(int m) {
  //write your code here
  int n = 0;
  while (m>=10)
  {
	m = m - 10;
	n++;
  }
  while (m>=5)
  {
	m = m - 5;
	n++;
  }
  while (m>=1)
  {
	m = m - 1;
	n++;
  }
  return n;
}

int main() {
  int m;
  std::cin >> m;
  clock_t startTime = clock();
  std::cout << get_change(m) << '\n';
  clock_t endTime = clock();
  std::cout << double(endTime - startTime) / CLOCKS_PER_SEC << "  S" << std::endl;
}
