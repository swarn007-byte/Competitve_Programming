#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <functional>

using namespace std;

void solve()
{
   int n;
   int k;
   cin>>n>>k;

   set<int>st;
   
   vector<int>a(n);

   for(auto &it:a)cin>>it;

   for(auto it:a){
    st.insert(it);
   }
   
   vector<int> last(k + 1, 0), max1(k + 1, 0), max2(k + 1, 0);
   
   for(int i=0;i<n;i++){
    int color = a[i];
    int gap = (i + 1) - last[color] - 1; 
    
    if (gap > max1[color]) {
        max2[color] = max1[color];
        max1[color] = gap;
    } else if (gap > max2[color]) {
        max2[color] = gap;
    }
    
    last[color] = i + 1;
   }
   
   for(auto color : st){
    int gap = (n + 1) - last[color] - 1;
    
    if (gap > max1[color]) {
        max2[color] = max1[color];
        max1[color] = gap;
    } else if (gap > max2[color]) {
        max2[color] = gap;
    }
   }
   
   long long ans = n; 
   
   for(auto color : st){
    long long current = max(max1[color] / 2, max2[color]);
    ans = min(ans, current);
   }
   
   cout<<ans<<endl;
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--)
        solve();

    return 0;
}