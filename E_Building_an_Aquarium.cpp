#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int n;
    long long w;
    cin >> n >> w;

    vector<long long> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    long long l = 0;
    long long r = *max_element(a.begin(), a.end()) + w;

    while (l < r) {
        long long mid = l + (r - l + 1) / 2;

        long long water = 0;
        for (int i = 0; i < n; i++) {
            water += max(0LL, mid - a[i]);
        }

        if (water <= w) {
            l = mid;      
        } else {
            r = mid - 1; 
        }
    }

    cout << l << "\n"; 
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