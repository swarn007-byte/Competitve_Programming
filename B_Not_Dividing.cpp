#include <iostream>

using namespace std;

typedef long long ll;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<long long> a(n);
        for (auto& x : a) cin >> x;

        // Step 1: make all 1s into 2s
        for (auto& x : a) {
            if (x == 1) x = 2;
        }

        // Step 2: for each pair, fix divisibility
        for (int i = 0; i < n - 1; i++) {
            if (a[i + 1] % a[i] == 0) {
                a[i + 1]++;  // increment by 1 breaks divisibility
            }
        }

        for (int i = 0; i < n; i++) {
            cout << a[i] << " \n"[i == n - 1];
        }
    }
    return 0;
}