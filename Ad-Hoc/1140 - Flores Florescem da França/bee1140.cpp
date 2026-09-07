// Beecrowd 1140 - Flores Florescem da França
#include <bits/stdc++.h>

using namespace std;

char toLower(char& c) {
    /*
    @brief Retorna a versão minúscula de um caractere
    @param c Caractere a ser transformado para minúsculo
    @return Caractere minúsculo
    */

    if (c >= 'A' && c <= 'Z') return c + 32;
    else return c;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // Lendo as frases de entrada. Finaliza quando a frase é "*"
    string str;
    while (getline(cin, str) && str[0] != '*') {
        // Encontra o primeiro caractere para o tautograma 
        char c;
        for (char s : str) { 
            if (s != ' ') { 
                c = toLower(s);
                break;
            }
        }
        bool flag = true; // Flag para tautograma
        for (int i = 1; i < str.size();i++) {
            // Encontra a primeira letra de uma palavra
            if (str[i-1] == ' ' && str[i] != ' ') {
                // Se for diferente do primeiro caractere encontrado
                if (toLower(str[i]) != c) {
                    flag = false; // Marca como um não-tautograma
                    break;
                } 
            }
        }
        // Se for um tautograma (flag=true)
        if (flag) cout << "Y\n";
        // Caso não for (flag=false)
        else cout << "N\n";
    }

    return 0;
}
