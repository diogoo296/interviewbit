#include <vector>
#include <iostream>

using namespace std;

int maxSubArray(vector<int> &A) {
    if (A.size() == 1) return A[0];
    
    int i, sum = A[0], maxSum = A[0];
    
    for (i = 1; i < A.size(); i++) {
      sum += A[i];
      if (A[i] >= sum) {
        sum = A[i];
      }
      maxSum = max(sum, maxSum);
    }
    
    return maxSum;
}

int main() {
  vector<int> A;

  A.push_back(-163);
  A.push_back(-20);
  
  cout << maxSubArray(A) << endl;

  return 0;
}
