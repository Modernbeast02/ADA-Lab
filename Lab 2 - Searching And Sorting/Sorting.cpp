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

void merge(int *arr, int s, int e) {

    int mid = (s+e)/2;
    int len1 = mid - s + 1;
    int len2 = e - mid;
    int *first = new int[len1];
    int *second = new int[len2];
    int mainArrayIndex = s;
    for(int i=0; i<len1; i++) {
        first[i] = arr[mainArrayIndex++];
    }
    mainArrayIndex = mid+1;
    for(int i=0; i<len2; i++) {
        second[i] = arr[mainArrayIndex++];
    } 
    int index1 = 0;
    int index2 = 0;
    mainArrayIndex = s;

    while(index1 < len1 && index2 < len2) {
        if(first[index1] < second[index2]) {
            arr[mainArrayIndex++] = first[index1++];
        }
        else{
            arr[mainArrayIndex++] = second[index2++];
        }
    }   
    while(index1 < len1) {
        arr[mainArrayIndex++] = first[index1++];
    }
    while(index2 < len2 ) {
        arr[mainArrayIndex++] = second[index2++];
    }
}

void mergeSort(int *arr, int s, int e) {
    if(s >= e) {
        return;
    }
    int mid = (s+e)/2;
    mergeSort(arr, s, mid);
    mergeSort(arr, mid+1, e);
    merge(arr, s, e);

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
    int arr[] = {45, 6, 2, 21, 7, 2};
    mergeSort(arr, 0, 5);
    for (int i = 0; i < 6; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    // Ques 5
    int arr[] = {45, 6, 2, 21, 7, 2, 6, 2, 12, 65};
    mergeSort(arr, 0, 9);
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
