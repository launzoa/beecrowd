#include <stdio.h>
#include <stdlib.h>

int **create_matrix(int n) {
  int **matrix = (int **)malloc(n * sizeof(int *));

  for (int i = 0; i < n; i++) {
    matrix[i] = (int *)malloc(n * sizeof(int));
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      matrix[i][j] = 0;
    }
  }
  return matrix;
}

void print_matrix(int **matrix, int n, int m) {
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      printf("%d ", matrix[i][j]);
    }
    printf("\n");
  }
}

void free_matrix(int **m, int n) {
  for (int i = 0; i < n; i++) {
    free(m[i]);
  }
  free(m);
}

int main() {
  int N, n, m, idx1, idx2, ASCII = 97;
  char c1, c2;
  scanf("%d", &N);

  for (int i = 0; i < N; i++) {
    scanf("%d %d", &n, &m);

    int **matrix = create_matrix(n);
    int qntd;
    int total = 0;
    print_matrix(matrix, n, qntd);

    for (int j = 0; j < m; j++) {
      scanf(" %c %c", &c1, &c2);
      idx1 = (int)c1 - ASCII;
      idx2 = (int)c2 - ASCII;

      if (j == 0) {
        matrix[0][idx1] = 1;
        matrix[0][idx2] = 1;
        qntd = 1;
        continue;
      }

      int found = 0;
      for (int k = 0; k < qntd; k++) {
        if (matrix[k][idx1] == 1 || matrix[k][idx2] == 1) {
          matrix[k][idx1] = 1;
          matrix[k][idx2] = 1;
          found = 1;
          break;
        }
      }

      if (!found) {
        if (qntd < n) {
          matrix[qntd][idx1] = 1;
          matrix[qntd][idx2] = 1;
        }
      }
    }
    for (int i = 0; i < n; i++) {
      int zero = 1;
      for (int j = 0; j < qntd; j++) {
        if (matrix[j][i] == 1) {
          zero = 0;
        }
      }
      if (zero) {
        matrix[i][i] = 1;
      }
    }
    printf("Case #%d:\n", i + 1);
    print_matrix(matrix, n, n);
    free_matrix(matrix, n);
  }

  return 0;
}
