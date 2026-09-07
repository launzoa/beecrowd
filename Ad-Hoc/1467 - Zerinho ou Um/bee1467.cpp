// Beecrowd 1467 - Zerinho ou Um
#include <bits/stdc++.h>

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Leitura para EOF para dois ou um básico
    int A, B, C;
    while (cin >> A >> B >> C) {
        // Se A é diferente de B (0 != 1)
        if (A != B) {
            // Então verifica se A é diferente de C (i.e., B = C)
            if (A != C) cout << "A";
            // Ou se A = C, logo B é o diferente
            else cout << "B";
        }
        // Se não, então A = B
        else {
            // Verifica se A = C (i.e,. A = B = C) 
            if (A == C) cout << "*";
            // Se não, então A = B != C
            else cout << "C";
        }

        cout << "\n";
    } 

    return 0;
}
