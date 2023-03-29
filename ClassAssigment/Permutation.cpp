#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl '\n'

#ifndef ONLINE_JUDGE
#include "debugger.h"
#else
#define debug(...) 1;
#endif

void FindPermutations(vector<ll> &current, vector<ll> &freq, vector<ll> &v, vector<vector<ll>> &ans)
{
    if (current.size() == v.size())
    {
        ans.push_back(current);
        return;
    }
    for (int i = 0; i < v.size(); i++)
    {
        if (!freq[i])
        {
            freq[i] = 1;
            current.push_back(v[i]);
            FindPermutations(current, freq, v, ans);
            freq[i] = 0;
            current.pop_back();
        }
    }
}
void solve()
{
    ll n;
    cin >> n;
    vector<ll> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    vector<ll> freq(n, 0);
    vector<ll> current;
    vector<vector<ll>> ans;
    FindPermutations(current, freq, v, ans);
    for (int i = 0; i < ans.size(); i++)
    {
        for (auto it : ans[i])
        {
            cout << it << " ";
        }
        cout << endl;
    }
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
