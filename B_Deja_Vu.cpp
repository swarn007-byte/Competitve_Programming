#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    
    while(t--){
        int n, q;
        cin >> n >> q;
        
        vector<long long> a(n);
        for(auto &x : a) cin >> x;
        
        vector<int> queries(q);
        for(auto &x : queries) cin >> x;
        
   
        set<int, greater<int>> unique_x(queries.begin(), queries.end());
        
        for(auto &val : a){
           
            for(int x : unique_x){
                long long pow2x = 1LL << x;
                if(val % pow2x == 0){
                    val += (1LL << (x - 1));
                    break; 
                }
            }
        }
        
        for(int i = 0; i < n; i++){
            cout << a[i];
            if(i < n-1) cout << ' ';
        }
        cout << '\n';
    }
    
    return 0;
}