#include <bits/stdc++.h>
using namespace std;
bool dfs(vector<int> adj[], bool *arr, int n,int src,int parent)
{
    arr[src] = true;
    queue<pair<int,int>> q;
    q.push({src,parent});
    while(!q.empty()){
        pair<int,int> p = q.front();
        q.pop();
        for(auto it:adj[p.first]){
            if(!arr[it]){
                arr[it]=1;
                q.push({it,p.first});
            }
            else if(it != p.second){
                    return true;
            }
        }
    }
    return false;
}

int main()
{
    vector<int> adj[5];
    adj[0].push_back(1);
    adj[0].push_back(2);

    adj[1].push_back(0);
    adj[1].push_back(3);
    adj[1].push_back(4);

    adj[3].push_back(2);
    adj[3].push_back(0);

    adj[4].push_back(1);

    adj[2].push_back(0);
    adj[2].push_back(3);

    bool arr[5] = {false};
    cout<<dfs(adj, arr, 5,0,-1);

    return 0;
}