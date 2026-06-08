#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define ff first
#define ss second
#define mp make_pair
#define ios ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

int main()
{   
    ios;
    #ifndef ONLINE_JUDGE
    freopen("input1.txt", "r", stdin);
    freopen("/Users/sreejith/Desktop/output.txt", "w", stdout);
    #endif
    ll t;
    cin>>t;
    while(t--) {
        ll n,b,c=0,state=0;
        cin>>n;
        vector < ll > v;
        for(ll i = 0 ; i < n ; i++) {
            cin>>b;
            v.push_back(b);
        }
        if(n==1) {
            cout<<1<<endl;
            continue;
        }
        for(ll i = 1 ; i < n ; i++) {
            if((v[i-1] > v[i]) and state!=1){
                c++;
                state = 1;
            }
            else if((v[i-1] < v[i]) and state!=-1) {
                c++;
                state = -1;
            }
        }
        cout<<c+1<<"\n";
    }
    return 0;     
 }        