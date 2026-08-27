// Beecrowd 1008 - Salário
#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    int n,hora;
    double sal;
    float media;

    cin >> n;
    cin >> hora;
    cin >> sal;

    media = hora*sal;

    cout << "NUMBER = " << n << "\n";
    cout << "SALARY = U$ " << fixed << setprecision(2) << media << "\n";

    return 0;
}
