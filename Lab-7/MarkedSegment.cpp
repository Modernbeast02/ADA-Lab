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
    vector<pair<ll, ll>> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i].first >> v[i].second;
    }
    sort(v.begin(), v.end(), [](pair<ll, ll> &a, pair<ll, ll> &b)
         { return a.second < b.second; });

    vector<ll> ans;
    ans.push_back(v[0].second);
    for (int i = 1; i < n; i++)
    {
        if (v[i].first <= ans.back())
        {
            continue;
        }
        ans.push_back(v[i].second);
    }
    cout << ans.size() << endl;
    for (auto &it : ans)
    {
        cout << it << " ";
    }
    cout << endl;
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
