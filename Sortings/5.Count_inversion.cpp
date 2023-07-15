#include <bits/stdc++.h>
using namespace std;

int merge_count(int *a, int l, int mid, int r)
{
    int low = l;
    int right = mid + 1;
    vector<int> arr;
    int res = 0;
    while (low <= mid and right <= r)
    {
        if (a[low] <= a[right])
        {
            arr.push_back(a[low]);
            low++;
        }
        else
        {
            arr.push_back(a[right]);

            // key step
            res += mid - low+1;
            right++;
            
        }
    }
    while (low <= mid)
    {
        arr.push_back(a[low]);
        low++;
    }

    while (right <= r)
    {
        arr.push_back(a[right]);
        right++;
    }

    for (int i = l; i <= r; i++)
    {
        a[i] = arr[i - l];
    }
    return res;
}

int merge_sort(int *a, int l, int r)
{
    if (l >= r)
    {
        return 0;
    }
    int res = 0;
    int mid = (l + r) / 2;
    res += merge_sort(a, l, mid);
    res += merge_sort(a, mid + 1, r);
    res += merge_count(a, l, mid, r);
    return res;
}

int main()
{
    int a[] = {7,2,3,4,5,6,1};
    cout<<merge_sort(a, 0, 6)<<"\n";
    for (int i = 0; i < 7; i++)
    {
        cout << a[i] << " ";
    }
    return 0;
}