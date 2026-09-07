// Beecrowd 1091 - Divisão da Nlogônia
#include <bits/stdc++.h>

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Leitura da quantidade de pontos 
    int K;
    while (cin >> K && K != 0) {
        // Leitura do ponto de origem (N, M)
        int N, M;
        cin >> N >> M;
        
        while (K--) {
            // Entra com os N pontos 
            int x, y;
            cin >> x >> y;
            // Calcula as coordeandas transladadas, i.e., x' = x-x_0, y' = y-y_0
            int x_t = x-N;
            int  y_t = y-M;
            // Verifica se está no Eixo X ou Eixo Y
            if (y_t == 0 || x_t == 0 ) cout << "divisa\n";
            // Se não, verifica em qual quadrante se encontra
            else {
                // Se está no 1º quad., então é Nordeste
                if (x_t > 0 && y_t > 0) cout << "NE\n";  
                // Se está no 2º quad., então é Noroeste
                else if (x_t < 0 && y_t > 0) cout << "NO\n";  
                // Se está no 3º quad., então é Suldoeste 
                else if (x_t < 0 && y_t < 0) cout << "SO\n";  
                // Se não, está no 4º quad., então é Suldeste
                else cout << "SE\n";
            }
        } 

    }

    return 0;
}
