#include <bits/stdc++.h>
using namespace std;
void bfs(vector<int> adj[], int n)
{
    queue<int> q;
    vector<int> indegeree(n, 0);
    for (int i = 0; i < n; i++)
    {
        for (auto it : adj[i])
        {
            indegeree[it]++;
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (indegeree[i] == 0)
        {
            q.push(i);
        }
    }
    while (!q.empty())
    {
        int u = q.front();
        cout << u << " -> ";
        q.pop();
        for (auto it : adj[u])
        {
            indegeree[it]--;
            if (indegeree[it] == 0)
            {
                q.push(it);
            }
        }
    }
}

int main()
{
    
    vector<int> adj[5];
    adj[0].push_back(1);
    adj[1].push_back(2);
    adj[3].push_back(1);
    adj[4].push_back(1);
    adj[3].push_back(2);
    bfs(adj,5);

    return 0;
}