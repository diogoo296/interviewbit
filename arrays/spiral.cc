#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

vector<int> spiralOrder(const vector<vector<int> > &A) {
  int M = A.size(), N = A[0].size();
  int total = M * N, i = 0, j = -1, direction = 0;
  int firstI = 0, firstJ = 0;
  vector<int> result;
  
  while (total > 0) {
    if (direction == 0) {
      j++;
      if (j == N - 1) {
        direction = 1;
        N--;
      }
    } else if (direction == 1) {
      i++;
      if (i == M - 1) {
        direction = 2;
        firstI++;
      }
    } else if (direction == 2) {
      j--;
      if (j == firstJ) {
        direction = 3;
        firstJ++;
      }
    } else if (direction == 3) {
      i--;
      if (i == firstI) {
        direction = 0;
        M--;
      }
    }

    result.push_back(A[i][j]);
    total--;
  }
  
  return result;
}

int main () {
  vector<vector<int>> input;
  int M = 1, N = 3;

  for (int i = 0; i < M; i++) {
    vector<int> row;
    for (int j = 1; j <= N; j++) {
      row.push_back(N*i + j);
      cout << N*i + j << " ";
    }
    input.push_back(row);
    cout << endl;
  }
  cout << endl;

  vector<int> result = spiralOrder(input);

  for (int i = 0; i < result.size(); i++) {
    cout << result[i] << " ";
  }
  cout << endl;
}
