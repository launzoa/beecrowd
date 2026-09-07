// Beecrowd 1216 - Getline One
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // Inicializando os contadores de distância e de quantidade de alunos
    double dist = 0;
    int count = 0;
    // Leitura do nome e da distância até a casa do amigo
    string name;
    int d;
    while(getline(cin, name) && cin >> d) {
        cin.ignore(); // Ignore para remover o '\n'
        dist += d; // Somatório para todas as distâncias entre as casas
        count++; // Contador para a quantidade de amigos
    }

    cout << setprecision(1) << fixed << dist / count << "\n";

    return 0;
}
