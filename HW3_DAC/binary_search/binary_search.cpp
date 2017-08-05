#include <iostream>
#include <cassert>
#include <vector>

using std::vector;

extern int L=0;

int binary_search(const vector<int> &a, int x) 
{
  int left = 0, right = (int)a.size(); 
  //write your code here
  if (x < a[0] || x > a[right-1])
  {
	L = 0;
	return -1;
  }
  else
  {
	  int mid = (right - 1 - left) / 2;
	  
	  //std::cout << "!mid = " << mid << std::endl;
	  
	  if (x == a[mid])
	  {
		int l = L;
		L = 0;
		return mid+l;
	  }
	  if (x < a[mid])
	  {
		if (right%2 == 0)
		{
			vector<int> b(right/2 - 1);
			for (size_t i = 0; i < b.size(); i++)
			{
				b[i] = a[i];
			}
			return binary_search(b, x);
		}
		else 
		{
			vector<int> b(right/2);
			for (size_t i = 0; i < b.size(); i++)
			{
				b[i] = a[i];
			}
			return binary_search(b, x);
		}
	  }
	  else if (x > a[mid])
	  {
		vector<int> b(right/2);
		for (size_t i = 0; i < b.size(); i++)
		{
			b[i] = a[mid+1+i];
		}
		L = L + mid+1;
		return binary_search(b, x);
	  }
  }
}

int linear_search(const vector<int> &a, int x) 
{
  for (size_t i = 0; i < a.size(); ++i) 
  {
    if (a[i] == x) return i;
  }
  return -1;
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
    //replace with the call to binary_search when implemented
    //std::cout << linear_search(a, b[i]) << ' ';				//serch b[i] in array a
	std::cout << binary_search(a, b[i]) << ' ';
  }
  
  
}
