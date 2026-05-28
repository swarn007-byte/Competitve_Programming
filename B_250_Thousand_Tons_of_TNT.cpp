#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {

    int n;
    cin >> n;

    vector<long long> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<long long> pref(n + 1, 0);

    for (int i = 0; i < n; i++) {
        pref[i + 1] = pref[i] + a[i];
    }

    long long ans = 0;

    for (int k = 1; k <= n; k++) {

        if (n % k != 0) continue;

        long long mn = 1e18;
        long long mx = -1e18;

        for (int i = 0; i < n; i += k) {

            long long sum = pref[i + k] - pref[i];

            mn = min(mn, sum);
            mx = max(mx, sum);
        }

        ans = max(ans, mx - mn);
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