#include <iostream>

long long lcm_naive(int a, int b) {
  for (long l = 1; l <= (long long) a * b; ++l)
    if (l % a == 0 && l % b == 0)
      return l;

  return (long long) a * b;
}

long long gcd(long long a, long long b)
{
	if (a < b)
	{
		long long tmp = b;
		b = a;
		a = tmp;
	}
	if (b == 0)
		return a;
	while (a >= b)
	{
		a = a - b;
	}

	return gcd(a, b);
}

long long lcm(int a, int b)
{
	return a / gcd(a, b) * b;
}

int main() {
  int a, b;
  std::cin >> a >> b;
  //std::cout << gcd(a, b) << std::endl;
  std::cout << lcm(a, b) << std::endl;
  //system("pause");
  return 0;
}
