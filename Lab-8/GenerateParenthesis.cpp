#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl '\n'

vector<string> ans;
void FindValidParenthesis(ll left, ll right, string &s)
{
    if (left > right)
    {
        return;
    }
    if (left < 0 || right < 0)
    {
        return;
    }
    if (left == 0 && right == 0)
    {
        ans.push_back(s);
        return;
    }
    s += '(';
    FindValidParenthesis(left - 1, right, s);
    s.pop_back();
    s += ')';
    FindValidParenthesis(left, right - 1, s);
    s.pop_back();
}
void solve()
{
    ll n;
    cin >> n;
    if (n < 1)
    {
        cout << -1 << endl;
        return;
    }
    string s = "";
    FindValidParenthesis(n, n, s);
    for (auto c : ans)
    {
        cout << c << " ";
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
