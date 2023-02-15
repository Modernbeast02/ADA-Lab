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

void merge(int input[], int left[], int right[], int sizeL, int sizeR)
{
    int i = 0;
    int j = 0;
    int *output = new int[sizeL + sizeR];
    int k = 0;
    while (i < sizeL && j < sizeR)
    {
        if (left[i] < right[j])
        {
            output[k] = left[i];
            i++;
            k++;
        }
        else if (left[i] > right[j])
        {
            output[k] = right[j];
            j++;
            k++;
        }
        else if (left[i] == right[j])
        {
            output[k] = left[i];
            output[k + 1] = right[j];
            i++;
            j++;
            k = k + 2;
        }
    }
    while (i < sizeL)
    {
        output[k] = left[i];
        i++;
        k++;
    }
    while (j < sizeR)
    {
        output[k] = right[j];
        j++;
        k++;
    }

    for (int i = 0; i < sizeL + sizeR; i++)
    {
        input[i] = output[i];
    }
}

void mergeSort(int input[], int size)
{
    if (size == 0 || size == 1)
    {
        return;
    }
    int mid = (size - 1) / 2;
    int *left = new int[mid + 1];
    for (int i = 0; i < mid + 1; i++)
    {
        left[i] = input[i];
    }
    int *right = new int[size - mid - 1];
    for (int i = 0; i < size - mid - 1; i++)
    {
        right[i] = input[mid + 1 + i];
    }
    mergeSort(left, mid + 1);
    mergeSort(right, size - mid - 1);
    merge(input, left, right, mid + 1, size - mid - 1);
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
    int input[] = {45, 6, 2, 21, 7, 2};
    mergeSort(input, 6);
    for (int i = 0; i < 6; i++)
    {
        cout << input[i] << " ";
    }
    cout << endl;
    
    // Ques 5
    mergeSort(list, 0, 9);
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
