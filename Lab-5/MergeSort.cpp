#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl '\n'

void merge(int *arr, int s, int e)
{
   int mid = (s + e) / 2;
   int len1 = mid - s + 1;
   int len2 = e - mid;
   int *first = new int[len1];
   int *second = new int[len2];
   int mainArrayIndex = s;
   for (int i = 0; i < len1; i++)
       first[i] = arr[mainArrayIndex++];
   mainArrayIndex = mid + 1;
   for (int i = 0; i < len2; i++)
       second[i] = arr[mainArrayIndex++];
   int index1 = 0;
   int index2 = 0;
   mainArrayIndex = s;
   while (index1 < len1 && index2 < len2)
   {
       if (first[index1] < second[index2])
              arr[mainArrayIndex++] = first[index1++];
       else
              arr[mainArrayIndex++] = second[index2++];
   }
   while (index1 < len1)
          arr[mainArrayIndex++] = first[index1++];
   while (index2 < len2)
       arr[mainArrayIndex++] = second[index2++];
}

void mergeSort(int *arr, int s, int e)
{
   if (s >= e)
   {
       return;
   }
   int mid = (s + e) / 2;
   mergeSort(arr, s, mid);
   mergeSort(arr, mid + 1, e);
   merge(arr, s, e);
}

void solve()
{
   int arr[] = {27, 17, 2, 13, 19, 7, 18};
   mergeSort(arr, 0, 6);
   cout << "Sorted List Using Merge Sort - \n";
   for (int i = 0; i < 7; i++)
   {
       cout << arr[i] << " ";
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
