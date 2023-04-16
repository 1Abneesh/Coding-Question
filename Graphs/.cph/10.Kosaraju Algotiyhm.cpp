#include <bits/stdc++.h>
using namespace std;
void dfs_rec_topological(vector<vector<int>> graph, stack<int> &st, vector<int> &visited, int src, int vert)
{
    visited[src] = 1;
    for (int i = 0; i < vert; i++)
    {
        if (!visited[i] && graph[src][i])
        {
            dfs_rec_topological(graph, st, visited, i, vert);
        }
    }
    st.push(src);
}

void dfs_rec(vector<vector<int>>& graph, vector<int> &visited, int src, int vert,vector<int>& dum)
{
    visited[src] = 1;
    cout << src << " ";
    for (int i=0;i<5;i++)
    {
        if (!visited[i] && graph[src][i])
        {
            dfs_rec(graph, visited, i, vert,dum);
        }
    }
}

void transpose(vector<vector<int>> &graph, vector<vector<int>> &graph_transpose,int vert)
{
    for (int i = 0; i < vert; i++)
    {
        for (int j = 0; j < vert; j++)
        {
                graph_transpose[j][i]=graph[i][j];
        }
    }
}

int main()
{
    vector<vector<int>> graph(5, vector<int>(5, 0));
    vector<vector<int>> transpose_graph(5, vector<int>(5, 0));
    stack<int> st;
    vector<int> visited(5, 0);
    graph[0][1] = 1;
    graph[2][0] = 1;
    graph[1][2] = 1;
    graph[3][2] = 1;
    graph[4][3] = 1;
    graph[3][4] = 1;

    for (int i = 0; i < 5; i++)
    {
        if (!visited[i])
        {
            dfs_rec_topological(graph, st, visited, i, 5);
        }
    }
    cout<<"Graph before transpose\n";
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            cout<<graph[i][j]<<" ";
        }cout<<"\n";
    }

    transpose(graph,transpose_graph, 5);

    cout<<"\nGraph after transpose\n";
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            cout<<transpose_graph[i][j]<<" ";
        }cout<<"\n";
    }

    int i = 0;
    vector<int> dummy(5,0);
    while (!st.empty())
    {
        cout << st.top() << " ";
        dummy[i] = st.top();
        st.pop();
        i++;
    }

    cout<<"\ndummy :- ";
    for(int i =0;i<5;i++){
        cout<<dummy[i]<<" ";
    }
    cout << "\n";

    for (int i = 0; i < 5; i++)
    {
        visited[i] = 0;
    }

    cout << "The strongly comppoonent are :-\n";
    for (auto it:dummy)
    {
        if (!visited[it])
        {
            // cout<<dummy[i]<<" ";
            dfs_rec(transpose_graph, visited, it, 5,dummy);
            cout << "\n";
        }
    }

    return 0;
}
