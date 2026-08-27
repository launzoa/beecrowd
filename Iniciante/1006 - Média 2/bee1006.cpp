// Beecrowd 1006 - Média 2
#include <iomanip>
#include <iostream>

using namespace std;

int main() {
    double a, b, c;
    float mean;

    cin >> a;
    cin >> b;
    cin >> c;

    mean = (a*0.2) + (b*0.3) + (c*0.5);

	cout << "MEDIA = " << fixed << setprecision(1) << mean << "\n";

    return 0;
}
