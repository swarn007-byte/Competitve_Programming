#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void solve(){
    int n;
    cin >> n;
    string s;
    cin >> s;

 
    int zero = 0;
    for(int i = 0; i < n; i++){
        if(s[i] == '0') zero++;
    }

    if(is_sorted(s.begin(), s.end())){
        cout << "Bob\n";
        return;
    }

    vector<int> ans;


    for(int i = 0; i < zero; i++){
        if(s[i] == '1') ans.push_back(i + 1); 
    }
    int k = ans.size();
    for(int i = n - 1; i >= zero; i--){
        if(s[i] == '0' && k > 0){
            ans.push_back(i + 1); 
            k--;
        }
    }

    sort(ans.begin(), ans.end());

    cout << "Alice\n";
    cout << ans.size() << "\n";
    for(auto it : ans){
        cout << it << " ";
    }
    cout << "\n";
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