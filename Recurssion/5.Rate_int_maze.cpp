class Solution{
    public:
    void solve(string ds,vector<string>& ans,vector<vector<int>> &m, int n,int x,int y,vector < vector < int >> vis){
        if(x==n-1 && y==n-1){
            ans.push_back(ds);
            return;
        }
        if(x+1<n && m[x+1][y]!=0 && !vis[x+1][y]){
            
            vis[x][y]=1;
            ds.push_back('D');
            solve(ds,ans,m,n,x+1,y,vis);
            ds.pop_back();
            vis[x][y]=0;
        }
        if(x-1>=0 && m[x-1][y]!=0   && !vis[x-1][y]){
            
            vis[x][y]=1;
            ds.push_back('U');
            solve(ds,ans,m,n,x-1,y,vis);
            ds.pop_back();
            vis[x][y]=0;
        }
        if(y+1<n && m[x][y+1]!=0 && !vis[x][y+1]){
            
            vis[x][y]=1;
            ds.push_back('R');
            solve(ds,ans,m,n,x,y+1,vis);
            ds.pop_back();
            vis[x][y]=0;
            
        }
        if(y-1>=0 && m[x][y-1]!=0 && !vis[x][y-1]){
            
            vis[x][y]=1;
            ds.push_back('L');
            solve(ds,ans,m,n,x,y-1,vis);
            ds.pop_back();
            vis[x][y]=0;
        }
    }
    
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        string ds = "";
        vector<string> ans;
        vector < vector < int >> vis(n, vector < int > (n, 0));
        int x = 0;
        int y = 0;
        if(m[0][0] ==1)solve(ds,ans,m,n,x,y,vis);
        return ans;
    }
};