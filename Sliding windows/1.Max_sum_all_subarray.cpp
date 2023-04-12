#include <bits/stdc++.h>
using namespace std;
int solve(int *a, int n)
{
    int k = 3;
    int i = 0;
    int j = 0;
    int res = 0;
    int sum = 0;
    while (j < n)
    {
        sum += a[j];
        if (j - i + 1 < k)
        {

            j++;
        }
        else if (j - i + 1 == k)
        {
            res = max(res, sum);
            sum -= a[i];
            i++;
            j++;
        }
    }
    return res;
}

int main()
{
    int a[] = {2, 3, 5, 7};
    cout << solve(a, 4);
    return 0;
}