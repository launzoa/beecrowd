#include <iostream>
#include <limits>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, x;
  unsigned long long val;
  cin >> n;

  while (n > 0) {
    n--;
    cin >> x;

    if (x == 64)
      val = numeric_limits<unsigned long long>::max();
    else
      val = 1ULL << x;

    val = (val / 12) / 1000;
    cout << val << " kg\n";
  }

  return 0;
}
