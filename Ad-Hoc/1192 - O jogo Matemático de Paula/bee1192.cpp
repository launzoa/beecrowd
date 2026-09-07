// Beecrowd 1192 - O jogo Matemático de Paula
#include <bits/stdc++.h>

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // Entra com a quantidade de entradas 
    int N;
    cin >> N;

    while (N--) {
        // Entra com cada string do tipo 'D:C:D', e.g., 1A1
        char s[4];
        cin >> s;
        // Extrai o valor inteiro desse dígito pela diferença ASCII
        int n1 = (s[0] - '0');
        int n2 = (s[2] - '0');
        // Se os dígitos forem iguais, então retorna o quadrado 
        if (n1 == n2) {
            cout << n2*n1 << "\n";
        }
        // Se a letra central for uma letra maiúscula, subtrai
        else if (s[1] >= 'A' && s[1] <= 'Z') {
            cout << n2-n1 << "\n";
        }
        // Se não, significa que a letra central é minúscula, adiciona 
        else {
            cout << n2+n1 << "\n";
        }
    }
    return 0;
}
