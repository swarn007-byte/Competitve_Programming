#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <functional>

using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> b(n);
        for(auto& x : b) cin >> x;
        
        sort(b.begin(), b.end(), greater<int>());
        
        bool ok = true;
        for(int i = 0; i + 2 < n; i++) {
            if(b[i] % b[i+1] != b[i+2]) {
                ok = false;
                break;
            }
        }
        
        if(ok) cout << b[0] << " " << b[1] << "\n";
        else cout << -1 << "\n";
    }
}