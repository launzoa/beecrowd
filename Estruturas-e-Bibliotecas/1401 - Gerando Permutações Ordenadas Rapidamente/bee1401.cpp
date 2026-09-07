// Beecrowd 1401 - Gerando Permutações Ordenadas Rapidamente
#include <bits/stdc++.h>

using namespace std;


void permutations(const string str, vector<bool> &c, string &v) {
    /*
    @brief Gera todas as permutações possíveis de uma string de forma recursiva

    @param str String que será permutada
    @param c Vetor de booleanos que indica se o caractere da posição i já foi usado na permutação atual 
    @param v String que contém a permutação atual 
    */

    // Se formou uma permutação
    if (str.size() == v.size()) {
        cout << v << "\n"; // Imprime a permutação
        return;
    }
    // Se não formou uma permutação
    else {
        // Percorre por todos os caracteres da string
        for (int i = 0; i < str.size(); i++) {
            if (c[i]) continue; // Se o caracter estiver marcado, pula pro próximo char
            // Se houver caracteres duplicados, ele faz o prunning: Como o vetor é ordenado
            // lexicográficamente, temos AAB, logo A_0 == A_1. Para tal, i > 0, se não podemos acessar 
            // i = -1. Além disso, o prunning só acontece no backtracking, que é quando c[i-1] é falso, 
            // já que adicionamos as permutações para A_0, e retornamos no backtracking no A_1, onde
            // A_0 é falso e já foi feita as permutações com o caractere A.
            if (i > 0 && str[i] == str[i-1] && !c[i-1]) continue;
            // Se não, adicionamos o caractere no vetor
            v.push_back(str[i]);
            c[i] = true; // Marcamos como escolhido
            // Chamamos recursivamente a função com esse novo vetor de permutação e de escolhidos
            permutations(str, c, v);
            // Ao retornar após o caso base, retiramos aquele caractere adicionado (backtracking)
            v.pop_back();
            c[i] = false; // E desmarcamos ele como escolhido
        }
    }
}


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // Entra com a quantidade de casos de teste
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        // Lê a string
        string s;
        cin >> s; 
        // Ordena a string para ficar lexicográficamente correto
        sort(s.begin(), s.end());
        // Inicializa os vetores  
        vector<bool> c(s.size(), false);
        string v;
        // Cria a permutação
        permutations(s, c, v);
        cout << "\n";
    }

    return 0;
}
