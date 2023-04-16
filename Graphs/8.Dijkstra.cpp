#include <bits/stdc++.h>
using namespace std;
void dijkstra(vector<vector<int>> graph, int v)
{
    bool visited[v] = {false};
    int distance[v];
    for (int i = 0; i < v; i++)
    {
        distance[i] = INT_MAX;
    }
    distance[0] = 0;
    for (int count = 0; count < v; count++)
    {
        int u = -1;
        for (int i = 0; i < v; i++)
        {
            if (!visited[i] && ((u == -1) || (distance[i] < distance[u])))
            {
                u = i;
            }
        }
        visited[u] = true;
        for (int j = 0; j < v; j++)
        {
            if (graph[u][j] != 0 && !visited[j])
            {
                distance[j] = min(distance[j], distance[u]+graph[u][j]);
            }
        }
    }
    for(int i=0;i<v;i++){
        cout<<distance[i]<<" ";
    }
}

int main()
{

    vector<vector<int>> graph(4, vector<int>(4, 0));
    // graph[0][1] = 5;
    // graph[1][0] = 5;
    // graph[1][3] = 15;
    // graph[3][1] = 15;

    // graph[1][2] = 10;
    // graph[2][1] = 10;

    // graph[2][3] = 20;
    // graph[3][2] = 20;

    // graph[0][2] = 8;
    // graph[2][0] = 8;

    graph[0][1] = 1;
    graph[1][3] = 2;
    graph[2][3] = 3;
    graph[1][2] = -8;
    graph[0][2] = 4;

    dijkstra(graph, 4);

    return 0;
}