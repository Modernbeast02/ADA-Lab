#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl '\n'

ll ConvertToHours(vector<ll> &v)
{
    ll hours = 0;
    for (int i = 0; i < 4; i++)
    {
        hours += v[i] * (1 << (3 - i));
    }
    return hours;
}
ll ConvertToMin(vector<ll> &v)
{
    ll minutes = 0;
    for (int i = 4; i < 10; i++)
    {
        minutes += v[i] * (1 << (9 - i));
    }
    return minutes;
}
void Insert(ll cur_time, string &time)
{
    if (cur_time > 9)
    {
        time += to_string(cur_time);
    }
    else
    {
        time += to_string(0);
        time += to_string(cur_time);
    }
}
void solve()
{
    ll n = 10;
    ll on_bits;
    cin >> on_bits;
    vector<vector<ll>> ans;
    for (int i = 0; i < (1 << n); i++)
    {
        vector<ll> x(10, 0);
        ll cnt = 0;
        for (int j = 0; j < n; j++)
        {
            if (i & (1 << j))
            {
                x[j] = 1;
                cnt++;
            }
        }
        if (cnt == on_bits)
        {
            ans.push_back(x);
        }
    }
    vector<string> res;
    for (auto it : ans)
    {
        ll hours = ConvertToHours(it);
        ll minutes = ConvertToMin(it);
        if (hours < 12 && minutes < 60)
        {
            string time = to_string(hours);
            time += ":";
            Insert(minutes, time);
            res.push_back(time);
        }
    }
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << " ";
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
