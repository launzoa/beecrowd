// Beecrowd 3456 - Divisibilidade por 7
#include <bits/stdc++.h>
using namespace std;

void divisibility_per_7(long long n) {
    while (n >= 10) {
        cout << n << "\n";

        long long b = n % 10;
        long long a = (n - b) / 10;

        n = 3*a + b;
    }

    cout << n << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n;
    if (cin >> n) {
        divisibility_per_7(n);
    }

    return 0;
}
