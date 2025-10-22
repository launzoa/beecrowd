#include <stdlib.h>
#include <stdio.h>

int** create_matrix(int n) {
  int* m = (int**) malloc(n * sizeof(int*))
  for (int i = 0; i < n; i++) {
    m[i] = (int*) malloc(n * sizeof(int))
  }
  return m;
}


void free(int** m, int n) {
  for (int i = 0; i < n; i++) {
    free(m[i]);
  }
  free(m);
}


int main() {
  int N,n,m;

   scanf("%d", &N);

  for (int i = 0; i < N; i++) {
    scanf("%d%d", &n, &m);
    int** matrix = create_matrix(n);
    fgets()
  }

  return 0;
}
