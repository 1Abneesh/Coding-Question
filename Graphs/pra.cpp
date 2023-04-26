#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[n];
        int a2[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++)
        {
            cin >> a2[i];
        }
        int i = 0;
        int j = 0;
        int ans = 0;
        int x = 0;
        int y = 0;
        int count = 0;
        bool flag = true;
        for (i = 1; i < n; i++)
        {
            if (a2[i] >= a2[i - 1])
            {
                count++;
                if (flag)
                {
                    j = i - 1;
                    flag = false;
                }
            }
            else
            {
                if (ans < count)
                {
                    bool flags = true;
                    map<int, int> mp;
                    for (int k = j; k < i; k++)
                    {
                        mp[a2[k]]++;
                        mp[a[k]]--;
                    }
                    for (auto it : mp)
                    {
                        if (it.second != 0)
                        {
                            flags = false;
                            break;
                        }
                    }
                    if (flags)
                    {
                        ans = count;
                        x = j;
                        y = i - 1;
                    }
                }
                count = 0;
                flag = true;
            }
        }
        if (count > ans)
        {
            bool flags = true;
            map<int, int> mp;
            for(int y=j;y<i-1;y++){
            for (int k = y; k < i; k++)
            {
                mp[a2[k]]++;
                mp[a[k]]--;
            }
            for (auto it : mp)
            {
                if (it.second != 0)
                {
                    flags = false;
                    break;
                }
            }
            if (flags)
            {
                ans = count;
                x = j;
                y = i - 1;
            }
        }
        }
        cout << x + 1 << " " << y + 1 << "\n";
    }
    return 0;
}