#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005; // 10^5

struct Round {
    int c;          // Número que dita a divisibilidade da rodada
    long long d;    // Quantidade de casas que os afetados recuam
};

int N, Q;
long long A[MAXN];          // Posição inicial de cada participante (A_i)
Round rounds[MAXN];         // Vetor com o histórico de todas as rodadas

vector<int> prime_factors[MAXN]; // Guarda a lista de fatores primos únicos de i, e.g., prime_factor[12] = {2,3}

long long div_sum[MAXN]; // Armazena a soma acumulada de passos d de todas as rodadas em que c_q foi divisível

int L[MAXN];                // Limite inferior do intervalo de busca
int R[MAXN];                // Limite superior do intervalo de busca
int ans[MAXN];              // Número da rodada em que zerou, ou -1
vector<int> mid_bucket[MAXN];// Agrupa participantes pelo ponto médio

// CRIVO DE ERATÓSTENES: Pré-calcula os fatores primos únicos de todos os números de 2 até MAXN
void build_sieve() {
    for (int i = 2; i < MAXN; i++) {
        // Se a lista estiver vazia, i é primo!
        if (prime_factors[i].empty()) {
            // Insere o primo i em todos os seus múltiplos (i, 2i, 3i...)
            for (int j = i; j < MAXN; j += i) {
                prime_factors[j].push_back(i);
            }
        }
    }
}


// ATUALIZAÇÃO DE DIVISORES: Ao acontecer a rodada (c, d), decompõe c em todos os seus divisores e adiciona d em cada divisor
void add_divisors(int c, long long d) {
    for (int i = 1; i * i <= c; i++) {
        if (c % i == 0) { /// Se i é divisor de c, adiciona d em i
            div_sum[i] += d;
            // Se i não é o divisor complementar, adiciona d em c / i
            if (i * i != c) div_sum[c / i] += d;
        }
    }
}


// PRINCÍPIO DA INCLUSÃO-EXCLUSÃO (PIE): Função recursiva que gera todos os subconjuntos de fatores primos de um participante.
void pie(int idx, int prod, int count, const vector<int>& p, long long& total) {
    // Caso base
    if (idx == (int)p.size()) {
        if (count == 0) return; // Ignora o subconjunto vazio

        if (count % 2 != 0) total += div_sum[prod]; // Ímpar: soma (+)
        else total -= div_sum[prod]; // Par: subtrai/desconta a duplicata (-)

        return;
    }

    pie(idx + 1, prod, count, p, total); // Não inclui o primo p[idx] no produto
    pie(idx + 1, prod * p[idx], count + 1, p, total); // Inclui o primo p[idx] no produto
}

// Retorna a soma líquida de passos do participante id até o momento atual
long long get_steps(int id) {
    if (prime_factors[id].empty()) return 0; // Participante 1 não tem fatores primos

    long long total = 0;
    pie(0, 1, 0, prime_factors[id], total);
    return total;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    build_sieve(); // Executa o crivo logo no início

    if (!(cin >> N >> Q)) return 0;

    // Leitura das posições iniciais dos participantes
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
        L[i] = 1;      // Menor rodada possível em que pode zerar
        R[i] = Q;      // Maior rodada possível em que pode zerar
        ans[i] = -1;   // Assume -1 (caso nunca alcance zero)
    }

    // Leitura de todas as rodadas
    for (int q = 1; q <= Q; q++) {
        cin >> rounds[q].c >> rounds[q].d;
    }

    // BUSCA BINÁRIA PARALELA: A cada passagem, o intervalo [L, R] de todos os participantes cai pela metade.
    while (true) {
        bool active = false; // Flag para checar se ainda há participantes em busca

        // Limpa os baldes de agendamento
        for (int q = 1; q <= Q; q++) {
            mid_bucket[q].clear();
        }

        // Calcula o ponto médio de cada participante ativo e o coloca na fila
        for (int i = 2; i <= N; i++) { // O participante 1 nunca se move (fica -1)
            if (L[i] <= R[i]) {
                active = true;
                int mid = L[i] + (R[i] - L[i]) / 2;
                mid_bucket[mid].push_back(i); // Agenda avaliação do participante 'i' na rodada 'mid'
            }
        }

        // Se nenhum participante precisa mais de busca, encerra
        if (!active) break;

        // Limpa as caixinhas para simular a linha do tempo do zero (da rodada 1 até Q)
        fill(div_sum, div_sum + MAXN, 0LL);

        // Varre a linha do tempo uma única vez
        for (int q = 1; q <= Q; q++) {
            // Aplica a rodada atual
            add_divisors(rounds[q].c, rounds[q].d);

            // Avalia todos os participantes cujo mid coincidiu com a rodada q
            for (int id : mid_bucket[q]) {
                long long steps = get_steps(id);

                if (steps >= A[id]) {
                    // Já alcançou o zero até a rodada q:
                    // Salva q como candidata e tenta buscar uma rodada ainda menor na esquerda [L, mid - 1]
                    ans[id] = q;
                    R[id] = q - 1;
                } else {
                    // Ainda não alcançou o zero:
                    // Precisa de mais rodadas, busca na metade direita [mid + 1, R]
                    L[id] = q + 1;
                }
            }
        }
    }

    for (int i = 1; i <= N; i++) {
        cout << ans[i] << "\n";
    }

    return 0;
}
