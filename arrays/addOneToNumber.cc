#include <vector>
#include <iostream>

using namespace std;

vector<int> plusOne(vector<int> &A) {
  int i;
  vector<int> B;
  bool overflowFlag = false, zeroFlag = true;

  for (i = A.size() - 1; i >= 0; i--) {
    if (A[i] == 9) {
      A[i] = 0;
      if (i == 0) {
        B.push_back(1);
        overflowFlag = true;
      }
    } else {
      A[i]++;
      break;
    }
  }

  for (i = 0; i < A.size(); i++) {
    if (A[i] != 0) {
      zeroFlag = false;
    }
    if (!zeroFlag || overflowFlag) {
      B.push_back(A[i]);
    }
  }

  return B;
}
