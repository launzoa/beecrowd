// Beecrowd 1397 - Jogo do Maior
#include <bits/stdc++.h>

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    // Quantidade de casos de uso, 0 para finalizar
    while (cin >> n && n != 0) {
        int countA = 0, countB = 0; // Contadores para os jogadores A e B

        while (n--) {
            int a, b;
            cin >> a >> b; 
            // Se o jogador A for maior que o jogador B, então incrementa o vencedor A
            if(a > b) countA++; 
            // Se não, incrementa o jogador B
            else if (a < b) countB++;
            // Em caso de ambos serem iguais, não faz nada  
        }

        cout << countA << " " << countB << "\n";
    }

    return 0;
}
