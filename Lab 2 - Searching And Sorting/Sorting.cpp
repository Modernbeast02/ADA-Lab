#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl '\n'

#ifndef ONLINE_JUDGE
#include "debugger.h"
#else
#define debug(...) 1;
#endif

void SelectionSort(vector<ll> v)
{
    ll n = v.size();
    for (int i = 0; i < n; i++)
    {
        ll mini = v[i];
        ll ind = i;
        for (int j = i + 1; j < n; j++)
        {
            if (v[j] < mini)
            {
                mini = v[j];
                ind = j;
            }
        }
        swap(v[i], v[ind]);
    }
    cout << "Sorted List using Selection Sort - \n";
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
    cout << "Comparisons = " << (n * (n - 1)) / 2 << endl;
    cout << "Iterations = " << n << endl;
    cout << endl;
}
void BubbleSort(vector<ll> v)
{
    ll n = v.size();
    for (int i = 0; i < n; i++)
    {
        bool flag = true;
        for (int j = 0; j < n - i - 1; j++)
        {
            if (v[j] > v[j + 1])
            {
                flag = false;
                swap(v[j], v[j + 1]);
            }
        }
        if (flag)
        {
            break;
        }
    }
    cout << "Sorted List using Bubble Sort - \n";
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
    cout << "Comparisons = " << (n * (n - 1)) / 2 << endl;
    cout << "Iterations = " << n << endl;
    cout << endl;

    // The change in Time Complexity is that the best case time complexity of bubble sort is O(N)
}
void InsertionSort(vector<ll> v)
{
    ll n = v.size();
    for (int i = 1; i < n; i++)
    {
        int j = i;
        while (j > 0 && v[j - 1] > v[j])
        {
            swap(v[j - 1], v[j]);
            j--;
        }
    }
    cout << "Sorted List using Insertion Sort - \n";
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
    cout << "Comparisons = " << (n * (n - 1)) / 2 << endl;
    cout << "Iterations = " << n - 1 << endl;
    cout << endl;
}
void Merge(vector<ll> &v, ll low, ll mid, ll high)
{
    ll n = mid - low;
    ll m = high - mid;
    vector<ll> one, two;
    for (int i = 0; i < n; i++)
    {
        one.push_back(v[i + low]);
    }
    for (int i = 0; i < m; i++)
    {
        two.push_back(v[i + mid]);
    }
    ll i = 0, j = 0, k = low;
    while (i < one.size() && j < two.size())
    {
        if (one[i] < two[j])
        {
            v[k] = one[i];
            i++;
        }
        else
        {
            v[k] = two[j];
            j++;
        }
        k++;
    }
    while (i < one.size())
    {
        v[k] = one[i];
        i++;
        k++;
    }
    while (j < two.size())
    {
        v[k] = two[j];
        k++;
        j++;
    }
}
void MergeSort(vector<ll> &list, ll low, ll high)
{
    if (low < high)
    {
        ll mid = low + (high - low) / 2;
        MergeSort(list, low, mid);
        MergeSort(list, mid + 1, high);
        Merge(list, low, mid, high);
    }
}
void Print(vector<ll> v)
{
    ll n = v.size();
    for (int i = 0; i < n; i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}
void solve()
{
    vector<ll> list = {18, 56, 27, 7, 8, 4, 9, 31, 81, 1};
    ll n = list.size();

    // Ques 1
    SelectionSort(list);

    // Ques 2
    BubbleSort(list);

    // Ques 3
    InsertionSort(list);

    // Ques 4
    vector<ll> List1 = {7, 8, 18, 27, 56};
    vector<ll> List2 = {1, 4, 9, 31, 81};
    vector<ll> mainList = {7, 8, 18, 27, 56, 1, 4, 9, 31, 81};
    Merge(mainList, 0, 5, 10);
    Print(mainList);

    // Ques 5
    MergeSort(list, 0, 9);
    Print(list);
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
