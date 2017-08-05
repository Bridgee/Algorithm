#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;

long long max_dot_product(vector<int> a, vector<int> b)
{
  for (size_t i = 0; i < a.size(); i++)
  {
	  int minind1 = i;
	  int minind2 = i;
	  for (int j = i + 1; j < a.size(); j++)
	  {
		  if (a[j] < a[minind1])
			  minind1 = j;
		  if (b[j] < b[minind2])
			  minind2 = j;
	  }
	  std::swap(a[i], a[minind1]);
	  std::swap(b[i], b[minind2]);
  }	
	

  long long result = 0;
  for (size_t i = 0; i < a.size(); i++) 
  {
    result += ((long long) a[i]) * b[i];
  }
  return result;
}

int main() {
  size_t n;
  std::cin >> n;
  
  vector<int> a(n), b(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> a[i];
  }
  for (size_t i = 0; i < n; i++) {
    std::cin >> b[i];
  }
  
  std::cout << max_dot_product(a, b) << std::endl;
  
}
