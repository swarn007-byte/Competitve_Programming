#include<iostream>
using namespace std;

void solve(){
    int n;
    cin >> n;
    vector<int> a(n);

    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    
    vector<int> six,three,two,neither,ans;
    for(auto it:a){
        if(it%6==0)six.push_back(it);
        else if(it%2==0)two.push_back(it);
        else if(it%3==0)three.push_back(it);
        else neither.push_back(it);
    }

    for(auto it:six)ans.push_back(it);
    for(auto it:two)ans.push_back(it);
    for(auto it:neither)ans.push_back(it);  
    for(auto it:three)ans.push_back(it);   

    for(auto it:ans){
        cout<<it<<" "; 
    }
    cout<<"\n";
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