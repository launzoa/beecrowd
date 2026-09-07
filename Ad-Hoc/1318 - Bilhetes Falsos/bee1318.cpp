// Beecrowd 1318 - Bilhetes Falsos
#include <bits/stdc++.h>

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Lendo M bilhetes para N pessoas na festa
    int N, M;
    while (cin >> N >> M && (N != 0 && M != 0)) {
        vector<bool> valid(N+1, false); // Vetor para guarda os bilhetes únicos
        vector<bool> repeated(N+1, false); // Vetor para guardar os bilhete repetidos
        int count = 0; // Contador para a quantidade de bilhetes falsos
        while (M--) {
            // Lê M bilhetes 
            int T;
            cin >> T; 
            // Se o bilhete para a pessoa i possuir mais que 1, significa que há falsificações  
            if (valid[T] && !repeated[T]) {
                repeated[T] = true; // Marca o bilhete i como duplicado 
                count++; // Incrementa o contador de bilhetes duplicados
            }
            else valid[T] = true; // Se não, marca o bilhete original
        }
        cout << count << "\n";
    }

    return 0;
}
