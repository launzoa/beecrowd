// Beecrowd 2416 - Corrida
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // Lê as entradas (C: quantidade percorrida desejada, N: tamanho da pista)
    int C, N;
    cin >> C >> N;
    // Imprime o resto da divisão da quantidade percorrida pelo tamanho da pista 
    cout << C%N << "\n";
    return 0;
}
