#include<bits/stdc++.h>
using namespace std;
void func(string s,string ds,vector<string> &ans,int indx){
    ans.push_back(ds);
    for(int i=indx;i<s.size();i++){
        ds.push_back(s[i]);
        func(s,ds,ans,i+1); // error
        ds.pop_back();
    }
}

// void func_dfs(string s, string ds,vector<string> &ans,int indx){
//     if(indx==s.size()){
//         ans.push_back(ds);
//         return ;
//     }
//     string ds_1 = ds;
//     string ds_2 = ds;
//     ds_1.push_back(s[indx]);
//     func_dfs(s,ds_1,ans,indx+1);
//     func_dfs(s,ds_2,ans,indx+1);

// }



int main(){
    string s = "1101";
    string ds= "";
    vector<string> ans;
    func(s,ds,ans,0);
    for(auto it:ans){
        cout<<it<<" ";
    }
    return 0;
}