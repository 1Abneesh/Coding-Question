#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);  
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        bool flag = false;
        int i;
        for(i=1;i<=n;i++){
            int total_post = 0;
            total_post +=(i*(i-1))/2;
            total_post += ((n-i)*(n-i-1))/2;
            if(total_post == k){
                flag = true;
                break;
            }
        }
        if(flag){
            cout<<"YES\n";
            for(int j=0;j<i;j++){
                cout<<1<<" ";
            }
            for(int j=i;j<n;j++){
                cout<<-1<<" ";
            }cout<<"\n";
        }
        else{
            cout<<"NO\n";
        }
        }
    return 0;
}