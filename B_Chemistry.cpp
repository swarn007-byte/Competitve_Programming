#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

void solve() {

    int n, k;
    cin >> n >> k;

    string s;
    cin >> s;

    map<char, int> mpp;

    // Count frequency
    for (auto it : s) {
        mpp[it]++;
    }

    int count = 0;

    // Count odd frequencies
    for (auto it : mpp) {
        if (it.second % 2 != 0)
            count++;
    }

    if (count - 1 <= k)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
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