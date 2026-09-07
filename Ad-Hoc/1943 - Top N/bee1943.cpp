// Beecrowd 1943 - Top N
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // Vetor que marca os intervalos das possíveis 'tops' posições
    int tops[] = {1, 3, 5, 10, 25, 50, 100};
    // Lê a colocação
    int N;
    cin >> N;
    // Precorre por todas as 'tops' posições
    for (int t : tops) {
        if (N <= t) { // Se encontrar o intervalo da colocação
            cout << "Top " << t << "\n"; // Imprime
            break; // Saí do loop
        }
    }

    return 0;
}
