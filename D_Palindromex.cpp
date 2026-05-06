#include<iostream>
using namespace std;

void solve(){
    int n;
    cin>>n;
    vector<int>a(n),vis;

    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int ans=0;
    for(int i=0;i<n;i++){
        if(a[i]==0){
            int l=i;
            int r=i;
            while(a[l]==a[r]){
                vis[a[l]]=1;
                for(auto it:vis){
                    if(vis[it]!=1){
                        ans=max(ans,it);
                        break;
                    }
                }
            }
        }
    }
    cout<<ans<<endl;

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