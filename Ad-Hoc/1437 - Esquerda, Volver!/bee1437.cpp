// Beecrowd 1437 - Esquerda, Volver!
#include <bits/stdc++.h>

using namespace std;

struct Node {
    char value;
    struct Node* left = nullptr;
    struct Node* right = nullptr;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    // Mapeando as coordenadas Norte, Sul, Leste e Oeste como uma lista encadeada circular
    Node N{'N'}, L{'L'}, S{'S'}, O{'O'};
    N.right = &L;
    N.left = &O;
    L.right = &S;
    L.left = &N;
    S.right = &O;
    S.left = &L;
    O.right = &N;
    O.left = &S;
    // Lê as N instruções do sargento enquanto diferente de 0
    int n;
    while (cin >> n && n != 0) {
        Node* coord = &N; // Define que a coordenada inicial começa apontada para o Norte
        // Lê a instrução do sargento
        string str;
        cin >> str;
        // Para cada instrução (caractere) do sargento
        for (char c : str) {
            if (c == 'D') coord = coord->right; // Se for para a direita
            else coord = coord->left; // Se for para a esquerda
        }
        cout << coord->value << "\n";
    }

    return 0;
}
