class Solution{
public:
    // Function to determine if graph can be coloured with at most M colours such
    // that no two adjacent vertices of graph are coloured with same colour.
    
    bool isvalid(bool graph[101][101], int m, int n,int *col,int indx,int j){
        for(int i=0;i<n;i++){
            if(i!=indx && graph[indx][i] && col[i] == j){
                return false;
            }
        }
        return true;
    }
    
    
    
    bool solve(bool graph[101][101], int m, int n,int *col,int indx){
        if(indx==n){
            return true;
        }

               for(int j=0;j<m;j++){
                if(isvalid(graph,m,n,col,indx,j)){
                    col[indx] = j; 
                    if(solve(graph,m,n,col,indx+1)){
                        return true;
                    }
                        col[indx]=-1;
                }
            }
            return false;
    }

    bool graphColoring(bool graph[101][101], int m, int n) {
        // your code here
        int col[n];
        for(int i=0;i<n;i++){
            col[i] = -1;
        }
        return solve(graph,m,n,col,0);
    }
};