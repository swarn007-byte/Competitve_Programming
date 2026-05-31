#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int main()  // fix: long long->int
{
    long long t;
    cin >> t;
    while (t--)
    {
        long long n, k;
        cin >> n >> k;

        vector<long long> a(n);
        for(long long i=0;i<n;i++) cin>>a[i];
        sort(a.begin(),a.end());

        vector<long long> pre(n,a[0]);
        for(long long i=1;i<n;i++) pre[i]=pre[i-1]+a[i];

        long long diff=LLONG_MAX;  

        for(long long i=0;i<=k;i++){
            long long left=2*i;
            long long right=k-i;
            if(left+right>n) break;
            long long cost=(left>0?pre[left-1]:0)+(right>0?pre[n-1]-pre[n-right-1]:0);  // fix: correct cost
            diff=min(diff,cost);  // fix: was wrong formula
        }

        long long ans=pre[n-1];  // fix: total sum

        cout<<ans-diff<<"\n";
    }
}