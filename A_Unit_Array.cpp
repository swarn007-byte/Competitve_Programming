 
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <numeric> 
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int neg = 0;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            if (x == -1) neg++;
        }
        
        int ans = 0;
        if (neg % 2 == 1) {
            ans++;
            neg--;
        }
        
        if (neg > n/2) {
            ans += 2 * (neg - n/2);
        }
        
        cout << ans << endl;
    }
    return 0;
}