#include<bits/stdc++.h>
using namespace std;
    char next(char c){
        if(c=='z'){return 'a';}
        return char(int(c)+1);
    }
    
    string check(string a,string b){
        int i=0,j=0;
        while(i<a.length() && j<b.length()){
        if(b[j]==a[i] || b[j]==next(a[i])){i++; j++;}
        else{i++;}
        }
        if(j==b.length()){return "YES";}
        return "NO";
    }
    
    vector<string> checkSimilarPasswords(vector<string>& newPasswords, vector<string>& oldPasswords){
        vector<string> res;
        for(int i=0;i<newPasswords.size();i++){
        res.push_back(check(newPasswords[i], oldPasswords[i]));
        }
        return res;
    }

int main(){
    vector<string> s1;
    vector<string> s2;
    s1.push_back("baacbab");
    s1.push_back("accdb");
    s2.push_back("abdbc");
    s2.push_back("ach");
    vector<string> ans;
    ans = checkSimilarPasswords(s1,s2);
    cout<<ans[0]<<"\n";
    cout<<ans[1]<<"\n";
    
    return 0;
}