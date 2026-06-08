#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <numeric> // Required for std::gcd
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--) {
        int n; cin >> n;
        vector<int> a(n);
        int neg = 0;
        for(auto& x : a) { cin >> x; if(x == -1) neg++; }

        int ops = 0;

        if(neg % 2 != 0) { neg--; ops++; }

        while(neg > n - neg) { neg -= 2; ops += 2; }

        cout << ops << "\n";
    }
}