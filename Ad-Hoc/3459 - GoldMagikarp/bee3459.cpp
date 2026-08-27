// Beecrowd 3459 - GoldMagikarp
#include <bits/stdc++.h>
using namespace std;

void getNumberVector(const string &l, vector<long long>& v) {
    int n = l.size();
    if (n == 0) return;

    // Estrutura de um bloco (intervalo) de números
    struct Block {
        int start, end;
        string digits;
    };

    vector<Block> blocks;

    for (int i = 0; i < n; ) {
        // Se o dígito for um número
        if (isdigit(l[i])) {
            int start = i; // Marca o começo do intervalo que representa o número
            string d = ""; // String que armazena o número
            while (i < n && isdigit(l[i])) { // Enquanto for um número
                d += l[i];
                i++; // Avança para o próximo dígito
            }
            int end = i - 1; // Fim do bloco

            // Verifica se o bloco numérico é válido (se não existe letra antes ou após o bloco)
            bool flagPrev = (start == 0) || (l[start - 1] == ' ' || l[start - 1] == ',' || l[start - 1] == '.');
            bool flagPred = (end == n - 1) || (l[end + 1] == ' ' || l[end + 1] == ',' || l[end + 1] == '.');

            if (flagPrev && flagPred) { // Caso seja válido
                blocks.push_back({start, end, d}); // Adiciona o intervalo
            }
        } else { // Se o digíto não for um número
            i++; // Avança para o próximo dígito
        }
    }

    if (blocks.empty()) return; // Se não há nenhum bloco numérico formado

    string cur_num = blocks[0].digits; // pega o valor da string do primeiro bloco

    for (int i = 1; i < blocks.size(); i++) {
        int dist = blocks[i].start - blocks[i - 1].end - 1; // Tira a distância entre os índices do bloco atual com o antigo

        if (dist == 1) { // Se a distância for 1, significa que há uma possível separação por ' ', ',' ou '.'
            char sep = l[blocks[i - 1].end + 1];
            // Se o dígito que separa os dois blocos for um dígito válido (' ', ',', ou '.')
            if (sep == ' ' || sep == ',' || sep == '.') {
                cur_num += blocks[i].digits; // Concatena os dois blocos
                continue;
            }
        }

        v.push_back(stoll(cur_num)); // Adiciona o bloco ao vetor, como um long long (stoll: string->longlong)
        cur_num = blocks[i].digits;
    }
    // Após percorrer todos os blocos, adicona o último número ao vetor
    if (!cur_num.empty()) v.push_back(stoll(cur_num));
}

bool isSequence(const vector<long long>& v) {
    int n = v.size();

    for (int i = 0; i < n; i++) {
        long long x = v[i];
        bool flagProx = false; // Se o próximo número é uma sequência x+1

        for (int j = i + 1; j < n; j++) {
            if (!flagProx) { // Enquanto não encontrar a primeira sequência x+1
                if (v[j] == x + 1) flagProx = true;
            } else { // Encontrado a primeira sequência, agora procura a segunda sequência x+2
                if (v[j] == x + 2) return true;
            }
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;
    cin.ignore();

    vector<long long> v;
    for (int i = 0; i < n; i++) {
        string line;
        getline(cin, line);
        getNumberVector(line, v);
    }

    if (isSequence(v)) cout << "123\n";
    else cout << ":)\n";

    return 0;
}
