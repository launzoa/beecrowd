// Usando o algoritmo de Union Find (DSU)
#include <stdio.h>
#include <stdlib.h>

int parent[26]; // qntd de elementos ('a' até 'z' -> 27)
int ASCII = 97;
// Inicializar todos os "pais", onde cada elemento é o seu próprio "pai"
void initialize(int n) {
  for (int i = 0; i < n; i++)
    parent[i] = i;
}

int find(int i) {
  if (parent[i] == i)
    return i;

  parent[i] = find(parent[i]);

  return parent[i];
}

void unite(int a, int b) {
  int parent_a = find(a);
  int parent_b = find(b);

  if (parent_a != parent_b) {
    parent[parent_a] = parent_b;
  }
}

void printList(int n) {

  int visited[26] = {0};
  int cont = 0;

  for (int i = 0; i < n; i++) {
    if (visited[i] == 0) {
      cont++;

      int representative = find(i);

      for (int j = 0; j < n; j++) {
        if (find(j) == representative) {
          printf("%c,", (char)(j + ASCII));
          visited[j] = 1;
        }
      }
      printf("\n");
    }
  }
  printf("%d connected components\n\n", cont);
}

int main() {

  int num, n, m, idx_a, idx_b;
  char a, b;

  scanf("%d", &num);

  for (int i = 1; i <= num; i++) {
    scanf("%d %d", &n, &m);

    initialize(n);

    for (int j = 0; j < m; j++) {
      scanf(" %c %c", &a, &b);

      idx_a = (int)a - ASCII;
      idx_b = (int)b - ASCII;

      unite(idx_a, idx_b);
    }
    printf("Case #%d:\n", i);
    printList(n);
  }
}
