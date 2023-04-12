#include <bits/stdc++.h>
using namespace std;
vector<int> solve(int *a, int n)
{
    int k = 3;
    int i = 0;
    int j = 0;
    list<int> lst;
    vector<int> ans;
    while (j < n)
    {
        while(lst.back()<a[j]&&!lst.empty()){
            lst.pop_back();
        }
        lst.push_back(a[j]);
        if (j - i + 1 < k)
        {
            j++;
        }
        else if (j - i + 1 == k)
        {
            ans.push_back(lst.front());
            if(lst.front()==a[i]){
                lst.pop_front();
            }
            i++;
            j++;
        }
    }
    return ans;
}

int main()
{
    int a[] = {2, 3, 5, 7};
    vector<int> res = solve(a, 4);
    for(auto it:res){
        cout<<it<<" ";
    }
    return 0;
}