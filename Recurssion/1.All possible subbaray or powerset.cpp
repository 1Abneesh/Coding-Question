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


int main(){
    string s = "Abne";
    string ds= "";
    vector<string> ans;
    func(s,ds,ans,0);
    for(auto it:ans){
        cout<<it<<" ";
    }
    
    
    
    return 0;
}