#include<iostream>
using namespace std;
void solve(){
    string s;
    cin >> s;
    int n = s.size();
    
    for(int i=0;i<n-1;i++){
        if((s[i]=='>' && s[i+1]!='>') ||
           (s[i+1]=='<' && s[i]!='<') ||
           (s[i]=='*' && s[i+1]=='*')){
            cout<<-1<<"\n";
            return;
        }
    }
    
    int l=0, r=n-1;
    while(l<n && s[l]!='>') l++;
    while(r>=0 && s[r]!='<') r--;
    
    cout<<max(l, n-r-1)<<"\n";
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