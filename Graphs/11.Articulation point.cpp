#include <bits/stdc++.h>
using namespace std;

void dfs_rec(vector<vector<int>> &graph, int &level, int src, vector<int> &discover, vector<int> &lower, vector<int> &visited, int parent, vector<int> &ap)
{
    int children = 0;
    visited[src] = 1;
    discover[src] = level;
    lower[src] = level;
    level += 1;
    for (int i = 0; i < graph.size(); i++)
    {
        if (graph[src][i] && !visited[i])
        {
            children++;
            dfs_rec(graph, level, i, discover, lower, visited, src, ap);

            lower[src] = min(lower[src], lower[i]);
            if (parent != -1 && discover[src] <= lower[i])
            {
                ap[src] = 1;
            }
        }
        else if (graph[src][i] && i != parent)
        {
            lower[src] = min(lower[src], discover[i]);
        }
    }
    if (parent == -1 && children > 1)
    {
        ap[src] = 1;
    }
}

int main()
{
    vector<vector<int>> graph(5, vector<int>(5, 0));
    vector<int> visited(5, 0);
    vector<int> ap(5, 0);
    graph[0][1] = 1;
    graph[1][2] = 1;
    graph[2][3] = 1;
    // graph[0][3] = 1;
    // graph[4][3] = 1;
    graph[3][4] = 1;
    int level = 1;
    vector<int> discover(5, 0);
    vector<int> lower(5, INT_MAX);
    for (int i = 0; i < 5; i++)
    {
        if (!visited[i])
        {
            // level += 1;
            dfs_rec(graph, level, i, discover, lower, visited, -1, ap);
        }
    }
    for (auto it : ap)
    {
        cout << it << " ";
    }
    cout << "\nThe lower value is :\n";
    for (auto it : lower)
    {
        cout << it << " ";
    }
    cout << "\nThe discover value is :\n";
    for (auto it : discover)
    {
        cout << it << " ";
    }

    return 0;
}