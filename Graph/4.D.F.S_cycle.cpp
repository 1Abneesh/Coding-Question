#include <bits/stdc++.h>
using namespace std;
bool dfs(vector<int> adj[], bool *arr, int n,int src,bool *curr)
{
    arr[src] = true;
    curr[src] = true;
    for(auto it:adj[src]){
        if(!arr[it]){
            if(dfs(adj,arr,n,it,curr)){
                return true;
            }
        }
        if(curr[it]==true){
            return true;
        }
    }
    curr[src] =false;
    return false;
}

int main()
{
    vector<int> adj[5];
    adj[0].push_back(1);
    adj[0].push_back(2);

    adj[1].push_back(2);

    adj[3].push_back(1);

    adj[4].push_back(3);

    adj[2].push_back(4);

    bool arr[5] = {false};
    bool curr[5] = {false};
    for(int i=0;i<5;i++){
        if(!arr[i]){
            if(dfs(adj, arr, 5,0,curr)){
                cout<<"Cycle detected";
            }
        }
    }

    return 0;
}