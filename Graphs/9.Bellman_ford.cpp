 #include <bits/stdc++.h>
using namespace std;
int bell_man_ford(vector<vector<int>> &graph, int src, int vertices)
{
    vector<int> distance(vertices, INT_MAX);
    distance[0] = 0;
    for (int count = 0; count < vertices - 1; count++)
    {

        for (int i = 0; i < vertices ; i++)
        {
            for (int j = 0; j < vertices; j++)
            {
                if (graph[i][j] != 0)
                {
                    distance[j] = min(distance[j], distance[i] + graph[i][j]);
                }
            }
        }
    }

    for (int i = 0; i < vertices; i++)
    {
        for (int j = 0; j < vertices; j++)
        {
            if (graph[i][j] != 0)
            {
                if (distance[j] > (distance[i] + graph[i][j]))
                
                    cout << "Negative edge found\n";
                }
            }
        }
    for (int i = 0; i < 4; i++)
    {
        cout << distance[i] << " ";
    }
    return distance[2];
}

int main()
{
    vector<vector<int>> graph(4, vector<int>(4, 0));
    graph[0][1] = 1;
    graph[1][3] = 2;
    graph[2][3] = 3;
    graph[1][2] = -258;
    graph[0][2] = 4;
    cout << bell_man_ford(graph, 0, 4);
    return 0;
}