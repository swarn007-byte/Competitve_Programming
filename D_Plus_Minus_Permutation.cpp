#include <iostream>

using namespace std;

typedef long long ll;

ll gcd(ll a, ll b) {
    while (b != 0) {
        ll temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

ll lcm(ll a, ll b) {
    if (a == 0 || b == 0) return 0;
    return (a / gcd(a, b)) * b;
}

ll get_sum(ll k) {
    if (k <= 0) return 0;
    if (k % 2 == 0) {
        return (k / 2) * (k + 1);
    } else {
        return k * ((k + 1) / 2);
    }
}

void solve(){
    ll n, x, y;
    cin >> n >> x >> y;

    ll u = n / x;
    ll v = n / y;
    ll w = n / lcm(x, y); // Using custom lcm here

    ll pos = u - w; 
    ll neg = v - w; 

    ll xsum = get_sum(n) - get_sum(n - pos);
    ll ysum = get_sum(neg);

    cout << xsum - ysum << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}