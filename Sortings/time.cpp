#include<bits/stdc++.h>
using namespace std;

vector<string> dictWord(string input){
    vector<int> ans;
    vector<int> res;
    stringstream ss(input);

    vector<string> v;

    while (getline(ss, s, ' ')) {
        res.push_back(s);
    }

    map<string,int> mp;
    for(auto it:res){
        mp[it] ++;
    }
    vector<pair<int,string>> vec;

    for(auto it:mp){
        vec.push_back({it.second,it.first});
    }
    sort(vec.begin(),vec.end());

    for(auto it:vec){
        ans.push_back(it.second);
    }
    return ans;

}

int main(){
    string s = "cat mat cat bat mat";
    vector<string> res = dictword(s);
    for(auto it:res){
        cout<<it<<" ";
    }
    return 0;
}