#include <iostream>

long long get_fibonacci_huge_naive(long long n, long long m) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }

    return current % m;
}

long long get_fibonacci_huge(long long n, long long m)
{
	if (m == 1)
	{
		if (n <= 1)
			return n;

		long long previous = 0;
		long long current = 1;

		for (long long i = 0; i < n - 1; ++i) {
			long long tmp_previous = previous;
			previous = current;
			current = tmp_previous + current;
		}

		return current;
	}
	///
	long long *temp = new long long [m];
	temp[0] = 0;
	temp[1] = 1;

	long long previous = 0;
	long long current = 1;
	int t = 2;

	for (int i = 0; i < 38; ++i) 
	{
		long long tmp_previous = previous;
		previous = current;
		current = tmp_previous + current;
		temp[i+2] = current % m;
		t++;
		if (temp[i + 2] == 1 && temp[i + 1] == 0)
			break;
	}
	t = t - 2;	//period
	return temp[n % t];
}

int main() {
 //   long long n, m;
 //   std::cin >> n >> m;
	//std::cout << get_fibonacci_huge(n, m) << '\n';
	long long m = 4;
	for (long long n = 0; n < 10; n++)
	{
		std::cout << get_fibonacci_huge(n, m) << '\n';
	}
    
	system("pause");
}
