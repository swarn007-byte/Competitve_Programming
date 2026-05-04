#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void solve(){
  
    int n, x, y;
    cin >> n >> x >> y;

    vector<long long> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    sort(a.begin(), a.end()); // simple ascending sort

    long long u = a[0]; // start with smallest

    for(int i = 1; i < n; i++){
        long long curr = a[i];

        if(u < curr){
            // u is sender, curr is receiver
            curr += (u / x) * (long long)y;
            u = curr;
        } else {
            // curr is sender, u is receiver
            u += (curr / x) * (long long)y;
        }
    }
    cout << u << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}