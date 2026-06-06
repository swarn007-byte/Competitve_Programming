#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <functional>

using namespace std;

void solve()
{
    int n;
    cin >> n;

    int m = n * (n - 1) / 2;
    vector<int> b(m);

    for (int i = 0; i < m; ++i)
        cin >> b[i];

    vector<int> a(n);
    map<int, int> mpp;

    priority_queue<
        pair<int, int>,
        vector<pair<int, int>>,
        greater<pair<int, int>>
    > pq;

    sort(b.begin(), b.end());

    for (auto x : b)
        mpp[x]++;

    for (auto p : mpp)
        pq.push({p.first, p.second});

    for (int i = 0; i < n - 1; i++)
    {
        int val = pq.top().first;
        int cnt = pq.top().second;
        pq.pop();

        a[i] = val;

        int newCnt = cnt - (n - i - 1);

        if (newCnt > 0)
            pq.push({val, newCnt});
    }

    a[n - 1] = 1000000000;

    for (auto x : a)
        cout << x << " ";
    cout << '\n';
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