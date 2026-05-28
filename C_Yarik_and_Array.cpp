#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    long long curr = a[0];
    long long ans = a[0];

    for (int i = 1; i < n; i++) {

        if (abs(a[i]) % 2 != abs(a[i - 1]) % 2) {

            curr = max((long long)a[i], curr + (long long)a[i]);

        } else {

            curr = a[i];
        }

        ans = max(ans, curr);
    }

    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
