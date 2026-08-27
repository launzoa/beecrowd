// Beecrowd 1008 - Salário
#include <stdio.h>

int main() {
    int n,h;
    double sal,sal_liq;

    scanf("%d", &n);
    scanf("%d", &h);
    scanf("%lf", &sal);


    sal_liq = sal*h;

    printf("NUMBER = %d\n", n);
    printf("SALARY = U$ %.2lf\n", sal_liq);
    return 0;
}
