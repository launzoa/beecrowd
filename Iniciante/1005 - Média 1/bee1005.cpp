// Beecrowd 1005 - Média 1
#include <iomanip>
#include <iostream>
using namespace std;

int main() {

  double A, B;
  float media;

  cin >> A;
  cin >> B;

  media = ((A * 0.35) + (B * 0.75)) / 1.1;

  cout << "MEDIA = ";
  cout << fixed << setprecision(5) << media << "\n";

  return 0;

  return 0;
}
