#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void solve(){
   int n;
   int q;
   cin >> n >> q;
   
   vector<int> a(n), b(n);
   for(int i = 0; i < n; i++) cin >> a[i];
   for(int i = 0; i < n; i++) cin >> b[i];

   int limit = min(n, q);

   int maxi = b[0]; 
   int result = 0;

   vector<int> pref(n, 0);
   pref[0] = a[0];

   for(int i = 1; i < limit; i++){
     pref[i] = pref[i-1] + a[i];
   }

   for(int i = 0; i < limit; i++){
      maxi = max(maxi, b[i]);
      
      int remaining_moves = q - 1 - i; 
      int current_score = pref[i] + (remaining_moves * maxi);
      
      result = max(result, current_score);
   }
   
   cout << result << endl;
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