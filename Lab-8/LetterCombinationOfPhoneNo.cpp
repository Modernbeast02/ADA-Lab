#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl '\n'

vector<string> ans;

vector<string> ipad = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

void FindAns(ll index, ll n, string &s, string &res)
{
    if (index == n)
    {
        ans.push_back(res);
        return;
    }
    for (auto it : ipad[s[index] - '0'])
    {
        res += it;
        FindAns(index + 1, n, s, res);
        res.pop_back();
    }
}
void solve()
{
    string s;
    cin >> s;
    ll n = s.size();
    if (n == 0)
    {
        cout << -1 << endl;
        return;
    }
    string res = "";
    FindAns(0, n, s, res);
    for (auto it : ans)
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
    // cin >> t
    while (t--)
        solve();
    return 0;
}
