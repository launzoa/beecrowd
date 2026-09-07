// Beecrowd 1245 - Botas Perdidas4
#include <bits/stdc++.h>

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Lê a quantidade de botas até um EOF
    int N;
    while(cin >> N) {
        // Vetores para armazenar os contadores de cada tamanho
        vector<int> left(31, 0);
        vector<int> right(31, 0);
        // Lê N botas
        while (N--) {
            int M; 
            char L;
            // Lê cada bota com um tamanho e respectivo pé
            cin >> M >> L; 
            // Parametriza o tamanho para um índíce do vetor 
            int idx = M-30;
            // Se o lado do pé escolhido for esquerdo 
            if (L == 'E') left[idx]++;
            // Se não, então foi direito
            else right[idx]++;
        }
        // Percorre cada tamanho do vetor para verificar a quantidade de pares formados
        int count = 0;
        for (int i = 0; i <= 30; i++) {
            // Encontra qual o menor entre os dois lados, 
            // sendo o número máximo de pares formados para aquele tamanho 
            if (left[i] <= right[i]) count += left[i];
            else count += right[i];
        }
        cout << count << "\n";
    }

    return 0;
}
