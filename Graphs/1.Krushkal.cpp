#include<bits/stdc++.h>
using namespace std;
class Edge{
    public:
    int src,dest,wt;
};

class Graph:public Edge{
    public:
    int ed;
    Edge *a;
    int *parent;
    int *rank;
    Edge *mst;
    int v;
    Graph(int e,int v){
        this ->ed = e;
        this->v=v;
        a = new Edge[e];
        mst = new Edge[e];
        parent = new int[v];
        rank = new int[v];
    }
    bool static my_comp(Edge e1,Edge e2){
        return e1.wt<e2.wt;
    }
    void add_edge(){
        for(int i=0;i<ed;i++){
            cout<<"Enter the source\n";
            cin>>src;
            cout<<"Enter the destination\n";
            cin>>dest;
            cout<<"Enter the wight\n";
            cin>>wt;
            a[i] = {src,dest,wt};
        }
    }
    int find(int x){
        if(parent[x] == x){
            return x;
        }
        return parent[x] = find(parent[x]);
        }
    
    void uni(int x, int y)
    {
        int s1 = find(x);
        int s2 = find(y);
 
        // if (s1 != s2) {
            if (rank[s1] < rank[s2]) {
                parent[s1] = s2;
                rank[s2] += rank[s1]+1;
            }
            else {
                parent[s2] = s1;
                rank[s1] += rank[s2]+1;
            }
    }
    int krushkal(){
        
        for(int i=0;i<v;i++){
            parent[i] = i;
            rank[i] = 0;
        }
        sort(a,a+ed,my_comp);
        int res = 0;
        for(int i=0, s=0;s<v-1;i++){
            Edge f = a[i];
            int x = find(f.src);
            int y= find(f.dest);
            if(x!=y){
                mst[s] = f;
                res += f.wt;
                uni(x,y);
                s++;
            }
            
        }
        for(int k=0;k<v-1;k++){
            cout<<mst[k].src<<"->"<<mst[k].dest<<"->";
        }
        return res;
    }
    
};
int main(){
    Graph g(7,5);
        g.add_edge();
    
    cout<<g.krushkal();
    
    return 0;
}


