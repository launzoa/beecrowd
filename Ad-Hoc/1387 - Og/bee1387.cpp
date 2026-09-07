// Beecrowd 1387 - Og
#include <bits/stdc++.h>

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Lê as quantidades de filhos e filhas, finalizando as entradas quando L = R = 0 
    int L, R;
    while (cin >> L >> R && (L != 0 && R != 0)) {
        // Soma e retorna a quantidade total de filhos
        cout << L + R << "\n";
    }

    return 0;
}
