#include <iostream>
#include <string>

using std::string;

int edit_distance(const string &str1, const string &str2) {
  //Init
  int opt[str1.size()+1][str2.size()+1];
  for (int i = 0; i<=str1.size(); i++){
	  opt[i][0] = i;
  }
  for (int j = 1; j<=str2.size(); j++){
	  opt[0][j] = j;
  }
  
  //DP_Function
  for (int i = 1; i <= str1.size(); i++){
	  for (int j =1; j <= str2.size(); j++){
		  int val1 = 0, val2 = 0, val3 = 0;
		  val1 = opt[i - 1][j] + 1;
		  val2 = opt[i][j - 1] + 1;
		  if (str1[i-1] == str2[j-1])
			  val3 = opt[i - 1][j - 1];
		  else
			  val3 = opt[i - 1][j - 1] + 1;
		  if (val2 < val1)
			  val1 = val2;
		  if (val3 < val1)
			  val1 = val3;
		  opt[i][j] = val1;
	  }
  }
  
  /*
  for (int i = 0; i <= str1.size(); i++){
	  for (int j =0; j <= str2.size(); j++){
		  if (j == str2.size())
			  std::cout << opt[i][j] << std::endl;
		  else
			  std::cout << opt[i][j] << "   ";
	  }
  }
  */
  
  return opt[str1.size()][str2.size()];
}

int main() {
  string str1;
  string str2;
  std::cin >> str1 >> str2;
  std::cout << edit_distance(str1, str2) << std::endl;
  return 0;
}
