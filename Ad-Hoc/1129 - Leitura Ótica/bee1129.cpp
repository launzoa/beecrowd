// Beecrowd 1129 - Leitura Ótica
#include <bits/stdc++.h>

using namespace std;

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Leitura dos casos de teste, enquanto N for diferente de zero
    int N;
    while(cin >> N && N != 0) {
        // Lê N entradas para as possíveis questões
        while (N--) {
            // Inicia as variáveis            
            int A, count = 0, idx = -1;
            // Lê as cinco possíveis entradas
            for (int i = 0; i < 5; i++) {
                cin >> A;
                // Conta quantos valores são menores/iguais à 127  
                if (A <= 127) { 
                    count++;
                    idx = i;
                }
            }
            // Se a quantidade de valores menores/iguais à 127 for igual à 1
            if (count == 1) {
                char C = 'A' + idx; // Encontra a letra que representa aquele valor
                cout << C << "\n"; // Imprime a respectiva letra
            }
            // Se não, não há resposta exata, logo '*'
            else {
               cout << "*\n";
            }
        }
    }

    return 0;
}
