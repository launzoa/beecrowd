// Beecrowd 1383 - Sudoku
#include <bits/stdc++.h>

using namespace std;

bool rowsIsValid(vector<vector<int>>& M) {

    for (int i = 0; i < 9; i++) {
        vector<bool> valid(10, false); // Vetor que armazena os números já usados
        for (int j = 0; j < 9; j++) {
            if (valid[M[i][j]]) return false;
            valid[M[i][j]] = true;
        }
    }

    return true;
}

bool colsIsValid(vector<vector<int>>& M) {
    
    for (int i = 0; i < 9; i++) {
        vector<bool> valid(10, false); // Vetor que armazena os números já usados
        for (int j = 0; j < 9; j++) {
            if (valid[M[j][i]]) return false;
            valid[M[j][i]] = true;
        }
    }

    return true;
}

bool blocksIsValid(vector<vector<int>>& M) {
    
    for (int l = 0; l < 3; l++) {
        for (int m = 0; m < 3; m++) {
            vector<bool> valid(10, false); // Vetor que armazena os números já usados
            int offset_rows = l*3; // Offset para percorrer 3 linhas
            int offset_cols = m*3; // Offset para percorrer 3 colunas 
            // Para cada bloco 3x3
            for (int i = offset_rows; i < offset_rows + 3; i++) {
                for (int j = offset_cols; j < offset_cols + 3; j++) {
                    if (valid[M[i][j]]) return false;
                    valid[M[i][j]] = true;
                }
            }
        }
    }

    return true;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Lendo a quantidade de jogos de sudoku 
    int N, k = 1;
    cin >> N;
    while (k <= N) {
    

        vector<vector<int>>M(9, vector<int>(9)); // Matriz que armazena um jogo
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                cin >> M[i][j]; // Lê cada cédula do jogo 
            }
        }
        cout << "Instancia " << k << "\n";
        k++;
        // Se alguma das condições for false, então o jogo não é possível
        if (!rowsIsValid(M) || !colsIsValid(M) || !blocksIsValid(M)) cout << "NAO\n\n";
        // Se todas as condições são verdadeiras, é possível
        else  cout << "SIM\n\n";
    }

    return 0;
}
