#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl '\n'

void solve()
{
    ll d, m;
    cin >> d >> m;
    ll n;
    cin >> n;
    vector<ll> v(n + 1);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    v[n] = d;
    sort(v.begin(), v.end());
    ll ans = 0;
    ll current = m;
    for (int i = 0; i < n + 1; i++)
    {
        if (i == 0)
        {
            current -= v[i];
        }
        else
        {
            current -= (v[i] - v[i - 1]);
        }
        if (current < 0)
        {
            current = m - (v[i] - v[i - 1]);
            ans++;
        }
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
