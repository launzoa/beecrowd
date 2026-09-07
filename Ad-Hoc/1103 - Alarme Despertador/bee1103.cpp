// Beecrowd 1103 - Alarme Despertador
#include <bits/stdc++.h>

using namespace std;

int main() {
    // O total de minutos em um dia: 24 horas * 60 minutos = 1440 minutos
    int MINUTES_MAX = 24 * 60;

    while (true) {
        // Leitura das horas e minutos do primeiro e segundo horários
        int H1, M1, H2, M2, res;
        cin >> H1 >> M1 >> H2 >> M2;
        // Se a entrada for 0 0 0 0, finaliza os casos de teste
        if (H1 == 0 && M1 == 0 && H1 == H2 && M1 == M2) break;
        // Convertendo os horários para minutos (por módulo do total). 
        int minutes1 = (H1 * 60 + M1) % MINUTES_MAX;
        int minutes2 = (H2 * 60 + M2) % MINUTES_MAX;
        // Se o primeiro horário for maior
        if (minutes1 > minutes2) {
            // Tira a diferença entre os horários
            int diff = minutes1 - minutes2;
            // Calcula o horário liquído da diferença 
            res = MINUTES_MAX - diff;
        }
        // Caso os horários forem iguais, então o total é 24 horas = 1440
        else if (H1 == H2 && M1 == M2) res = MINUTES_MAX;
        // Se não, apenas tira a diferença entre os dois
        else res = minutes2 - minutes1;
        cout << res << "\n";
    }

    return 0;
}
