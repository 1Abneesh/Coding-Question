#include <bits/stdc++.h>
using namespace std;
vector<int> solve(int *a, int n)
{
    int k = 3;
    int i = 0;
    int j = 0;
    queue<int> q;
    vector<int> ans;
    while (j < n)
    {
        if (a[j] < 0)
        {
            q.push(a[j]);
        }

        if (j - i + 1 < k)
        {
            j++;
        }
        else if (j - i + 1 == k)
        {
            if (q.empty())
            {
                ans.push_back(0);
            }
            else
            {
                ans.push_back(q.front());
            }
            if (a[i] < 0)
            {
                q.pop();
            }
            i++;
            j++;
        }
    }
    return ans;
}

int main()
{
    int a[] = {12, -1, -7, 8, -15, 30, 16, 28};
    vector<int> res = solve(a, 8);
    for (auto it : res)
    {
        cout << it << " ";
    }
    return 0;
}