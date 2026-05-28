#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void solve() {
    int n;
    cin >> n;
    
    // a[i] = {value, original_index}
    vector<pair<long long, int>> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].first;
        a[i].second = i;
    }
    
    sort(a.begin(), a.end());
    
    // p[i] = prefix sums
    vector<long long> p(n, 0);
    p[0] = a[0].first;
    for (int i = 1; i < n; i++) {
        p[i] = p[i - 1] + a[i].first;
    }
    
    // b[i] = max reachable index for sorted positions
    vector<int> b(n, 0);
    
    for (int i = 0; i < n; i++) {
        if (b[i] != 0) continue;
        
        int curr = i;
        while (true) {
            auto it = lower_bound(a.begin(), a.end(), pair<long long, int>{p[curr] + 1, 0});
            int next_idx = it - a.begin() - 1;
            
            if (next_idx == curr) {
                break;
            }
            curr = next_idx;
        }
        
        for (int k = i; k <= curr; k++) {
            b[k] = curr;
        }
    }
    
    // c[i] = final answers mapped to original indices
    vector<int> c(n);
    for (int i = 0; i < n; i++) {
        c[a[i].second] = b[i];
    }
    
    for (int i = 0; i < n; i++) {
        cout << c[i] << (i == n - 1 ? "" : " ");
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}