#include<bits/stdc++.h>
using namespace std;

int feb(int n){
    if(n<=1){
        return n;
    }
    return feb(n-1) +feb(n-2);
}

int main(){
    int ans = feb(3);
    cout<<ans<<"\n";
    
    return 0;
}