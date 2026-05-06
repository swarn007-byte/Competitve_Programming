#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void solve(){
  
  int n;
  cin >> n;
  string s;
  cin >> s;

  int z=0;
  int one=0;

  for(int i=0;i<n;i++){
     if(s[i]=='0') z++;
     if(s[i]=='1') one++;
  }

  bool canOne = (one%2==0);
  bool canZero = (z%2==1);

  auto print = [&](char c, int cnt){
    cout<<cnt<<"\n";
    if(cnt==0){ cout<<"\n"; return; }
    bool first=true;
    for(int i=0;i<n;i++){
      if(s[i]==c){
        if(!first) cout<<" ";
        cout<<i+1;
        first=false;
      }
    }
    cout<<"\n";
  };

  if(canOne && canZero){
    if(one<=z) print('1',one);
    else print('0',z);
  }else if(canOne){
    print('1',one);
  }else if(canZero){
    print('0',z);
  }else{
    cout<<-1<<"\n";
  }
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