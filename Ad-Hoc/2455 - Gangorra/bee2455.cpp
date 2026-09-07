// Beecrowd 2455 - Gangorra
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // Leitura de ambos os pesos dos garotos (P1 e P2), bem como os comprimentos da gangorra (C1 e C2)
    int P1, C1, P2, C2;
    cin >> P1 >> C1 >> P2 >> C2;
    // Verifica se o lado esquerdo da gangorra fica em baixo (menor que o direito)
    if (P1 * C1 < P2 * C2) cout << "1\n"; 
    // Se não, verifica se o lado direito da gangorra fica em baixo
    else if (P1 * C1 > P2 * C2) cout << "-1\n";
    // Caso nenhum dos lados estiver em baixo, então está equilibrado
    else cout << "0\n"; 

    return 0;
}
