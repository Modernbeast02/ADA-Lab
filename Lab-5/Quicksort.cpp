#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl '\n'
int partition(int arr[], int s, int e)
{
   int pivot = arr[s];
   int cnt = 0;
   for (int i = s + 1; i <= e; i++)
   {
       if (arr[i] <= pivot)
           cnt++;
   }
   int pivotIndex = s + cnt;
   swap(arr[pivotIndex], arr[s]);
   int i = s, j = e;
   while (i < pivotIndex && j > pivotIndex)
   {
       while (arr[i] <= pivot)
           i++;
       while (arr[j] > pivot)
           j--;
       if (i < pivotIndex && j > pivotIndex)
           swap(arr[i++], arr[j--]);
   }
   return pivotIndex;
}
void quickSort(int arr[], int s, int e)
{
   if (s >= e)
       return;
   int p = partition(arr, s, e);
   quickSort(arr, s, p - 1);
   quickSort(arr, p + 1, e);
}
void solve()
{
   int arr[10] = {2, 4, 1, 6, 9, 15, 10, 9, 11, 9};
   int n = 10;
   quickSort(arr, 0, n - 1);
   cout << "Sorted Array using Quicksort - \n";
   for (int i = 0; i < n; i++)
       cout << arr[i] << " ";
   cout << endl;
   //Time complexity= O(NlogN)
   //Worst case complexity = O(N^2)
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
