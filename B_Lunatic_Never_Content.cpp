#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <numeric> // This contains standard std::gcd
#include <cmath>   // For abs()

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &it : a) cin >> it;

    int l = 0, r = n - 1, ans = 0;

    while(l < r){
        if(a[l] != a[r])
            // FIX: Use standard std::gcd instead of internal __algo_gcd
            ans = std::gcd(ans, abs(a[r] - a[l]));
        l++;
        r--;
    }

    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}