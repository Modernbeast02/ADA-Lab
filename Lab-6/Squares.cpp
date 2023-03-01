#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl '\n'

void solve()
{
    ll n;
    cin >> n;
    vector<ll> v(n);
    ll maxi = -1;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        v[i] = abs(v[i]);
        maxi = max(maxi, v[i]);
    }
    vector<ll> freq(maxi + 1, 0);
    for (int i = 0; i < n; i++)
    {
        freq[v[i]]++;
    }
    vector<ll> squares;
    for (int i = 0; i < maxi + 1; i++)
    {
        ll cnt = freq[i];
        for (int j = 0; j < cnt; j++)
        {
            squares.push_back(i * i);
        }
    }
    for (int i = 0; i < squares.size(); i++)
    {
        cout << squares[i] << " ";
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
