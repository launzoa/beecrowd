#include <iostream>
#include <vector> 

using namespace std;


vector<long long int> F; 
long long int Factorial(int n) {
  if (F[n] == 0) {
    F[n] = n * Factorial(n-1);
  }
  return F[n];
} 

int main() {
  int x1,x2;

  F.assign(21, 0);
  F[0] = 1;

  while (cin >> x1 >> x2) {
    cout << Factorial(x1) + Factorial(x2) << "\n";
  }

  return 0;
} 
