#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl '\n'

#ifndef ONLINE_JUDGE
#include "debugger.h"
#else
#define debug(...) 1;
#endif

void solve()
{
    ll n;
    cin >> n;
    vector<vector<ll>> v(n);
    for (int i = 0; i < n; i++)
    {
        ll x, y;
        cin >> x >> y;
        v[i] = {x, y};
    }
    sort(v.begin(), v.end(), [](const vector<ll> &a, const vector<ll> &b)
         { return a[0] - a[1] < b[0] - b[1]; });
    ll ans = 0;
    for (int i = 0; i < n / 2; i++)
    {
        ans += v[i][0];
    }
    for (int i = n / 2; i < n; i++)
    {
        ans += v[i][1];
    }
    cout << ans << endl;
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
