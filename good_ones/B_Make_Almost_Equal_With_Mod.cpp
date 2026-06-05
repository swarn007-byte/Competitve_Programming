#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <numeric> 

using namespace std;
typedef long long ll;

void solve(){
    ll n;
    cin >> n;
    vector<ll> a(n);

    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    
    
    set<ll>st;
    ll rem=2;
    while(1){
        st.clear();
      for(int i=0;i<n;i++){
        st.insert(a[i]%rem);
      }
      if(st.size()==2){
        break;
      }
      rem*=2;
    }
    cout<<rem<<endl;
}

int main(){
    // Fast I/O optimization
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    // For your local testing environment
    freopen("Error.txt", "w", stderr);
#endif
    
    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}