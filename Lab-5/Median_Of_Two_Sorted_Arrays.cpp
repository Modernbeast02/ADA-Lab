#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl '\n'

#ifndef ONLINE_JUDGE
#include "debugger.h"
#else
#define debug(...) 1;
#endif

double FindMedian(vector<ll> &v1, vector<ll> &v2)
{
    if (v1.size() > v2.size())
    {
        return FindMedian(v2, v1);
    }
    ll n = v1.size();
    ll m = v2.size();
    ll low = 0, high = n;
    while (low <= high)
    {
        ll cut1 = low + (high - low) / 2;
        ll cut2 = (n + m + 1) / 2 - cut1;
        ll left1, left2, right1, right2;

        // Left Cut
        if (cut1 == 0)
        {
            left1 = -1e9;
        }
        else
        {
            left1 = v1[cut1 - 1];
        }
        if (cut2 == 0)
        {
            left2 = -1e9;
        }
        else
        {
            left2 = v2[cut2 - 1];
        }

        //Right Cut
        if (cut1 == n)
        {
            right1 = 1e9;
        }
        else
        {
            right1 = v1[cut1];
        }
        if (cut2 == m)
        {
            right2 = 1e9;
        }
        else
        {
            right2 = v2[cut2];
        }

        if (left1 <= right2 && left2 <= right1)
        {
            if ((n + m) % 2 == 0)
            {
                return ((max(left1, left2) + min(right1, right2)) / (2.0));
            }
            else
            {
                return max(left1, left2);
            }
        }
        else if (left1 > right2)
        {
            high = cut1 - 1;
        }
        else
        {
            low = cut1 + 1;
        }
    }
    return 0.0;
}
void solve()
{
    ll n, m;
    cin >> n >> m;
    vector<ll> v1(n), v2(m);
    for (int i = 0; i < n; i++)
    {
        cin >> v1[i];
    }
    for (int i = 0; i < m; i++)
    {
        cin >> v2[i];
    }
    cout << FindMedian(v1, v2) << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}
