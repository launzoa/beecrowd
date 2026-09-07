// Beecrowd 2456 - Cartas
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    bool flagC = true, flagD = true; // Flags para diferenciar cada ordenação 
    // Lê a primeira carta (usada como antecessora)
    int ant; 
    cin >> ant;
    // Lê as próximas 4 cartas
    for (int i = 1; i < 5; i++) {
        int suc;
        cin >> suc;
        // Se a carta atual for maior que antecessora
        if (suc >= ant) flagD = false; // Não é decrescente
        if (suc <= ant) flagC = false; // Se não, então não é crescente
        // A carta atual passa a ser a antecessora
        ant = suc;
    }

    if (flagC) cout << "C\n"; // Se for crescente
    else if (flagD) cout << "D\n"; // Se for decrescente
    else cout << "N\n"; // Se não tiver ordenação

    return 0;
}
