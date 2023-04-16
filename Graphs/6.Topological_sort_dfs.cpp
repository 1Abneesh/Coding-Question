#include <bits/stdc++.h>
using namespace std;
void dfs(vector<int> adj[], bool *arr, int n, int s, stack<int> &st)
{
    arr[s] = true;
    for (auto it : adj[s])
    {
        if (!arr[it])
        {
            dfs(adj, arr, n, it,st);
        }
    }
    st.push(s);
}

int main()
{
    vector<int> adj[5];
    adj[0].push_back(1);
    adj[1].push_back(2);
    adj[3].push_back(1);
    adj[4].push_back(1);
    adj[3].push_back(2);
    bool arr[5] = {false};
    stack<int> s;
    for (int i = 0; i < 5; i++)
    {
        if(!arr[i]){
        dfs(adj, arr, 5, i,s);
        }
    }
    while (!s.empty())
    {
        cout << s.top()<<"-> ";
        s.pop();
    }

    return 0;
}