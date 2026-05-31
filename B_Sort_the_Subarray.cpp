#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (auto &it : a) cin >> it;
    for (auto &it : b) cin >> it;

    int l = 0, r = n - 1;

    // Step 1: Find the absolute outermost boundaries where a and b differ
    while (l < n && a[l] == b[l]) {
        l++;
    }
    while (r >= 0 && a[r] == b[r]) {
        r--;
    }

    // Step 2: Maximize the window by expanding outward.
    // We can include b[l-1] if it is less than or equal to the current start of our sorted zone.
    while (l > 0 && b[l - 1] <= b[l]) {
        l--;
    }
    
    // We can include b[r+1] if it is greater than or equal to the current end of our sorted zone.
    while (r < n - 1 && b[r] <= b[r + 1]) {
        r++;
    }

    // Print 1-based indices
    cout << l + 1 << " " << r + 1 << "\n";
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}