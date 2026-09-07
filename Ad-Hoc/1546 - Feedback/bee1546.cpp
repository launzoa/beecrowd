// Beecrowd 1546 - Feedback
#include <bits/stdc++.h>

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // Determinando o vetor de respostas para cada setor de feedback
    vector<string>feedbacks(5);
    feedbacks[1] = "Rolien";
    feedbacks[2] = "Naej";
    feedbacks[3] = "Elehcim";
    feedbacks[4] = "Odranoel";
    // Lendo a quantidade N de casos de teste (dias)
    int N;
    cin >> N;
    while (N--) {
        // Lendo a quantidade K de feedbacks para cada dia
        int K;
        cin >> K;
        while (K--) {
            // Lendo cada feedback
            int f;
            cin >> f;
            // Imprimindo o responsável por aquele setor de feedback
            cout << feedbacks[f] << "\n";
        }
    }

    return 0;
}
