// Beecrowd 1329 - Cara ou Coroa
#include <bits/stdc++.h>

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    while (cin >> N && N != 0) {
        int count = 0;

        for (int i = 0; i < N; i++) {
            int k;
            cin >> k;
            if (k == 0) count++;
        }

        cout << "Mary won " << count << " times and John won " << N-count << " times\n";
    } 


    return 0;
}
