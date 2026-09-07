// Beecrowd 2454 - Fliper
#include <bits/stdc++.h>

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int P, R;
    cin >> P >> R;
    // Se P = 1, então fecha a porta da direita 
    if (P == 1) {
        // Se R = 1, então fecha a porta da direita
        if (R == 1) cout << "A" << "\n";
        // Se não, fecha a porta da esquerda
        else cout << "B" << "\n";
 
    }
    // Se não, fecha a porta da esquerda 
    else cout << "C" << "\n";

    return 0;
}
