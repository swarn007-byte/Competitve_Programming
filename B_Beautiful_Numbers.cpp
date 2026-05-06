#include<iostream>
#include<algorithm>
using namespace std;
void solve(){
    long long n;
    cin>>n;

    string s=to_string(n);

    int sum=0;
    for(char c:s) sum+=(c-'0');

    if(sum<=9){
        cout<<0<<"\n";
        return;
    }
    int k=s[0];
    int idx=0;

    string ns="";
    for(int i=0;i<(int)s.size();i++){
        ns+=s[i];
    }
    sort(ns.rbegin(),ns.rend());

    for(int i=0;i<(int)ns.size();i++){
        if(ns[i]==k) idx=i;
    }

    int gap=sum-9;
    int count=0;
    
    for(int i=0;i<(int)ns.size();i++){
        if(gap<=0){
            cout<<count<<"\n";
            return;
        }
        if(i==idx){
            gap-=(ns[i]-'0'-1);
        }else{
            gap-=(ns[i]-'0');
        }
        count++;
    }
    cout<<count<<"\n";
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