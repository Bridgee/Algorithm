#include <iostream>
#include <vector>

using std::vector;

double get_optimal_value(int capacity, vector<int> weights, vector<int> values) 
{
  double value = 0.0;
  int n = weights.size();
  vector<double> unit(n);
  if (capacity == 0)
	return 0;
  
  for (int i = 0; i < n; i++)
  {
	  unit[i] = double(values[i]) / double(weights[i]);
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
  
  for (int k = 0; k < n; k++)
  {
	  if (weights[k] <= capacity)
	  {
		  value = value + values[k];
		  capacity = capacity - weights[k];
	  }
	  else
	  {
		  value = value + (capacity * unit[k]);
		  capacity = 0;
	  }
  }
  
  return value;
}







int main() {
  int n;
  int capacity;
  std::cin >> n >> capacity;
  vector<int> values(n);
  vector<int> weights(n);
  for (int i = 0; i < n; i++) {
    std::cin >> values[i] >> weights[i];
  }

  double optimal_value = get_optimal_value(capacity, weights, values);

  std::cout.precision(10);
  std::cout << optimal_value << std::endl;
  return 0;
}
