#include <iostream>
#include <cassert>
#include <vector>

using std::vector;

int binary_search(const vector<int> &a, int low, int high, int x) 
{
  if (low > high)
	  return -1;
  int mid = (high - low) / 2 + low;
  
  //std::cout <<  "   (" << mid << ")   ";
  
  if (x == a[mid])
	  return mid;
  if (x < a[mid])
  {
	  return binary_search(a, low, mid - 1, x);
  }
  else
  {
	  return binary_search(a, mid+1, high, x);
  }

}


int main() 
{
  int n;				// number of the input
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); i++)				//input n integer numbers
  {
    std::cin >> a[i];
  }
  
  
  int m;
  std::cin >> m;				//number of serch
  vector<int> b(m);
  for (size_t i = 0; i < m; ++i) 
  {
    std::cin >> b[i];
  }
  
  
  for (int i = 0; i < m; ++i) 
  {
	std::cout << binary_search(a, 0, n-1, b[i]) << ' ';
  }
  
  
}
