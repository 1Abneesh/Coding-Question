#include <bits/stdc++.h>
using namespace std;
void bfs(vector<int> adj[], bool *arr, int n)
{
    queue<int> q;
    q.push(0);
    arr[0] = true;
    while (!q.empty())
    {
        int u = q.front();
        cout << u << " ";
        q.pop();
        for (auto it : adj[u])
        {
            if (!arr[it])
            {
                arr[it] = true;
                q.push(it);
            }
        }
    }
}

int main()
{
    vector<int> adj[5];
    adj[0].push_back(1);
    adj[0].push_back(3);
    adj[0].push_back(4);

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
    bfs(adj, arr, 4);

    return 0;
}