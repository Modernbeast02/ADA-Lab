#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl '\n'

void solve()
{
    ll n;
    cin >> n;
    ll ans = n / 10;
    n -= (n / 10) * 10;
    ans += (n / 5);
    n -= (n / 5) * 5;
    ans += n;
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
