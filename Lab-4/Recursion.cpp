#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl '\n'

#ifndef ONLINE_JUDGE
#include "debugger.h"
#else
#define debug(...) 1;
#endif

void FindSolution(ll index, ll n, string &s, vector<vector<char>> &total, vector<char> current)
{
    if (index == n)
    {
        total.push_back(current);
        return;
    }
    if (s[index] >= '0' && s[index] <= '9')
    {
        current.push_back(s[index]);
        FindSolution(index + 1, n, s, total, current);
    }
    else
    {
        current.push_back(s[index]);
        FindSolution(index + 1, n, s, total, current);
        current.pop_back();
        if (s[index] >= 'a' && s[index] <= 'z')
        {
            ll c = s[index] - 'a';
            current.push_back((char)(c + 'A'));
            FindSolution(index + 1, n, s, total, current);
        }
        else
        {
            ll c = s[index] - 'A';
            current.push_back((char)(c + 'a'));
            FindSolution(index + 1, n, s, total, current);
        }
    }
}
void solve()
{
    string s;
    cin >> s;
    ll n = s.size();
    vector<vector<char>> total;
    vector<char> current;
    FindSolution(0, n, s, total, current);
    for (auto it : total)
    {
        string s1 = "";
        for (auto ch : it)
        {
            s1 += ch;
        }
        cout << s1 << endl;
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
