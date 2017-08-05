#include <iostream>
#include <vector>

using std::vector;

int optimal_weight(int W, const vector<int> &w) {
  vector<int> optm((W+1) * (w.size()+1));
  
  //Init
  for (int i = 0; i < w.size() + 1; i++){
	  optm[0 * (w.size()+1) + i] = 0;
  }
  for (int i = 0; i < W + 1; i++){
	  optm[i * (w.size()+1) + 0] = 0;
  }
  
  //DP_Function
  for (int n = 1; n<=w.size(); n++){
	  for (int weight = 1; weight<=W; weight++){
		  optm[weight * (w.size()+1) + n] = optm[weight * (w.size()+1) + n - 1];	//Init
		  //std::cout << optm[weight][n] << std::endl;
		  //std::cout << "w = " << weight << ", w[n] = " << w[n - 1] << std::endl;
		  if (weight - w[n - 1] >= 0){
			  if (optm[(weight - w[n - 1]) * (w.size()+1) + (n - 1)] + w[n - 1] > optm[weight * (w.size()+1) + n]){
				  optm[weight * (w.size()+1) + n] = optm[(weight - w[n - 1]) * (w.size()+1) + (n - 1)] + w[n - 1];
				}
			  //std::cout << optm[weight][n] << "!!!" << std::endl;
		  }
		  
	  }
  }
  
  /*
  for (int i = 0; i < W+1; i++){
	  for (int j = 0; j < w.size() + 1; j++){
		  if (j == w.size())
			  std::cout << optm[i * (w.size()+1) + j] << std::endl;
		  else
			  std::cout << optm[i * (w.size()+1) + j] << "  ";
	  }
  }
  */
  
  return optm[W * (w.size()+1) + w.size()];
}


int main() {
  int n, W;
  std::cin >> W >> n;
  vector<int> w(n);
  for (int i = 0; i < n; i++) {
    std::cin >> w[i];
  }
  std::cout << optimal_weight(W, w) << '\n';
}
