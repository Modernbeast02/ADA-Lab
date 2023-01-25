//Ques 1

#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl '\n'

void LinearSearch(vector<ll> &to_be_searched, vector<ll> &v)
{
    ll n = v.size();
    ll m = to_be_searched.size();
    // Time Complexity of Linear Search for each element = O(N) where N is the size of the list
    // Total time complexity is O(NM) where M is the total number of elements to be searched
    for (int i = 0; i < m; i++)
    {
        bool flag = false;
        for (int j = 0; j < n; j++)
        {
            if (to_be_searched[i] == v[j])
            {
                cout << to_be_searched[i] << " is present at position " << j << endl;
                flag = 1;
                break;
            }
        }
        if (!flag)
        {
            cout << to_be_searched[i] << " is not present in the list\n";
        }
    }
}
void BinarySearch(vector<ll> &to_be_searched, vector<ll> &v)
{
    ll n = v.size();
    ll m = to_be_searched.size();
    sort(v.begin(), v.end());
    for (int i = 0; i < m; i++)
    {
        ll element = to_be_searched[i];
        ll low = 0;
        ll high = n;
        bool flag = false;
        while (low <= high)
        {
            ll mid = low + (high - low) / 2;
            if (v[mid] == element)
            {
                cout << element << " is present at index " << mid << endl;
                flag = 1;
                break;
            }
            else if (v[mid] > element)
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        if (!flag)
        {
            cout << element << " is not present in the list\n";
        }
    }
}
void solve()
{
    vector<ll> v = {1, 4, 7, 7, 8, 9, 18, 27, 31, 56, 81};
    vector<ll> to_be_searched = {1, 81, 7, 3};
    LinearSearch(to_be_searched, v);
    BinarySearch(to_be_searched, v);
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
