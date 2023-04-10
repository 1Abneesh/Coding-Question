#include <bits/stdc++.h>
using namespace std;
void dfs(vector<int> adj[], bool *arr, int n, int s)
{
    // stack<int> q;
    // q.push(0);
    arr[s] = true;
    cout << s << " ";
    // while (!q.empty())
    // {
    //     int u = q.top();
    //     cout << u << " ";
    //     q.pop();
    for (auto it : adj[s])
    {
        if (!arr[it])
        {
            dfs(adj,arr,n,it);
            // arr[it] = true;
            // q.push(it);
        }
    }
}

int main()
{
    vector<int> adj[5];
    adj[0].push_back(1);
    adj[0].push_back(4);
    adj[0].push_back(3);

    adj[1].push_back(0);
    adj[1].push_back(2);
    adj[1].push_back(4);

    adj[3].push_back(4);
    adj[3].push_back(2);
    adj[3].push_back(0);

    adj[4].push_back(3);
    adj[4].push_back(1);
    adj[4].push_back(0);

    adj[2].push_back(1);
    adj[2].push_back(3);

    bool arr[4] = {false};
    dfs(adj, arr, 4,0);

    return 0;
}