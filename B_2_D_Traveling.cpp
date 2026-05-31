#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

void solve() {
    long long n, k, a, b;  // fix: long long
    
    cin >> n >> k >> a >> b;
    a--; b--;

    vector<long long> x(n), y(n);  // fix: removed unused arr
    for (int i = 0; i < n; i++) cin >> x[i] >> y[i];

    long long dist = abs(x[b]-x[a]) + abs(y[b]-y[a]);  // fix: long long

    if(k == 0){  // fix: edge case
        cout << dist << "\n";
        return;
    }

    long long first = LLONG_MAX;  // fix: long long, not 1e9
    for(int i = 0; i < k; i++){  // fix: i < k not i < n
        first = min(first, abs(y[b]-y[i]) + abs(x[b]-x[i]));
    }

    long long second = LLONG_MAX;  // fix: long long, not 1e9
    for(int i = 0; i < k; i++){  // fix: i < k not i < n
        second = min(second, abs(y[a]-y[i]) + abs(x[a]-x[i]));
    }

    if(a < k) second = 0;  // fix: a is already major city
    if(b < k) first = 0;   // fix: b is already major city

    cout << min(dist, first + second) << "\n";
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