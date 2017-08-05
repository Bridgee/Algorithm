#include <iostream>
#include <vector>

using std::vector;
int main()
{
  int n;
  int capacity;
  std::cin >> n >> capacity;
  vector<int> values(n);
  vector<int> weights(n);
  for (int i = 0; i < n; i++) {
    std::cin >> values[i] >> weights[i];
  }
   vector<int> unit(n);
    for (int i = 0; i < n; i++)
  {
	  unit[i] = values[i] / weights[i];
  }
  
    for (int i = 0; i < n; i++)
  {
	  int maxind = i;
	  for (int j = i + 1; j < n; j++)
	  {
		  if (unit[j] > unit[maxind])
			  maxind = j;
	  }
	  std::swap(unit[i], unit[maxind]);
	  std::swap(values[i], values[maxind]);
	  std::swap(weights[i], weights[maxind]);
  }
  
  for (int i = 0; i < n; i++)
  {
    std::cout << unit[i]<<"    "<< values[i] << "    " << weights[i] << std::endl;
  }
  
  return 0;
}