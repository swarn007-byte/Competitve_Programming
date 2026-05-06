#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void solve(){
  
string s;
cin >> s;
int n = s.size();

  int ans=0;
  
  for(int i=0;i<n;i++){
    if(i+1<n && s[i]=='*' && s[i+1]=='*') ans=-1;
    if(i+1<n && s[i]=='>' && s[i+1]=='<') ans=-1;
    if(s[i]=='*'){
      if(i-1>=0 && i+1<n) ans=-1;
      if(i==0 && i+1<n && s[i+1]=='<') ans=-1;
      if(i==n-1 && i-1>=0 && s[i-1]=='>') ans=-1;
    }
  }

  if(ans==-1){
    cout<<-1<<"\n";
    return;
  }

  int left=0, right=0;
  for(int i=0;i<n;i++){
    if(s[i]=='<') left++;
    else break;
  }
  for(int i=n-1;i>=0;i--){
    if(s[i]=='>') right++;
    else break;
  }
  cout<<max({left, right, 1})<<"\n";
 
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