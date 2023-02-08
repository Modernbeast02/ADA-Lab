#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl '\n'

#ifndef ONLINE_JUDGE
#include "debugger.h"
#else
#define debug(...) 1;
#endif

void Print(stack<ll> st)
{
    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;
}
void InsertNumberAtBottom(stack<ll> &st, ll item)
{
    if (st.empty())
    {
        st.push(item);
        return;
    }
    ll top = st.top();
    st.pop();
    InsertNumberAtBottom(st, item);
    st.push(top);
}
void ReverseStack(stack<ll> &st)
{
    if (st.empty())
    {
        return;
    }
    ll item = st.top();
    st.pop();
    ReverseStack(st);

    InsertNumberAtBottom(st, item);
}
void solve()
{
    stack<ll> st;
    for (int i = 1; i <= 5; i++)
    {
        st.push(i);
    }
    Print(st);
    ReverseStack(st);
    Print(st);
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
