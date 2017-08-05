#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;

int get_majority_element(vector<int> &a, int left, int right) 
{
  if (left == right) 
	  return -1;		//no element
  if (left + 1 == right) 
	  return a[left];		//one element

  //Split
  int mid = (right - left ) / 2 + left;
  int LL = get_majority_element(a, left, mid);
  int RR = get_majority_element(a, mid, right);
		//std::cout << "!!! "<<LL<<" !!! "<< RR<<" !!!"<<std::endl;
  //Merge
  int count = 0;
  if (LL == -1 && RR == -1)
  {
	  return -1;
  }
  else if (LL == -1)
  {
	  for (size_t i = left; i < right; i++)
	  {
		  if (a[i] == RR)
			  count++;
	  }
	  //std::cout << "@@@ "<<count<<" @@@"<<std::endl;
	  if (count > (right - left)/2)
		  return RR;
	  else 
		  return -1;
  } 
  else if (RR == -1)
  {
	  for (size_t i = left; i < right; i++)
	  {
		  if (a[i] == LL)
			  count++;
	  }
	  //std::cout << "@@@ "<<count<<" @@@"<<std::endl;
	  if (count > (right - left)/2)
		  return LL;
	  else 
		  return -1;
  }
  else if(LL == RR)
	  return LL;
  else
  {
	  int count_l = 0;
	  int count_r = 0;
	  for (size_t i = left; i < right; i++)
	  {
		  if (a[i] == LL)
			  count_l++;
		  else if (a[i] == RR)
			  count_r++;
	  }
	  //std::cout << "??? "<< count_l  <<" ??? "<<  count_r <<" ???"<<std::endl;
	  if (count_l>count_r)
		  return LL;
	  if (count_l<count_r)
		  return RR;
	  if (count_l == count_r)
		  return -1;
  }

}

int main() 
{
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) 
  {
    std::cin >> a[i];
  }
  
  std::cout << (get_majority_element(a, 0, a.size())     !=     -1) << '\n';
}

