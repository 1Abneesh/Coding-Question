#include<bits/stdc++.h>
using namespace std;

int main(){
    int q,k;
    cin>>q>>k;
    int i=0;
    vector<int> ans;
    ans.push_back(k);
    q--;
    while(q>0){
      if((1<<i & k) == 0){
          ans.push_back((1<<i) | k);
          q--;
      }
      i++;
    }
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}