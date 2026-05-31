#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <stack>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, x;
        cin >> n >> x;
        bool ans = false;

        stack<int> a, b, c;
        vector<int> tmp(n);

        for (int i = 0; i < n; i++)
            cin >> tmp[i];
        for (int i = n - 1; i >= 0; i--)
            a.push(tmp[i]);

        for (int i = 0; i < n; i++)
            cin >> tmp[i];
        for (int i = n - 1; i >= 0; i--)
            b.push(tmp[i]);

        for (int i = 0; i < n; i++)
            cin >> tmp[i];
        for (int i = n - 1; i >= 0; i--)
            c.push(tmp[i]);

        long long v = 0;

        // Read from stack a
        while (!a.empty())
        {
            int top = a.top();
            if ((top | x) == x)
            {
                v = v | top;
                a.pop();
            }
            else
            {
                break;
            }
        }
        
        // Read from stack b
        while (!b.empty())
        {
            int top = b.top();
            if ((top | x) == x)
            {
                v = v | top;
                b.pop();
            }
            else
            {
                break;
            }
        }
        
        while (!c.empty())
        {
            int top = c.top();
            if ((top | x) == x)
            {
                v = v | top;
                c.pop();
            }
            else
            {
                break;
            }
        }

        if(v == x) ans = true;

        cout << (ans ? "Yes" : "No") << "\n";
    }
}