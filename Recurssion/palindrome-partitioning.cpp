class Solution {
public:

    bool isvalid(int i,int indx,string s){
        while(indx<=i){
            if(s[i]!=s[indx]){
                return false;
            }
            i--;
            indx++;
        }
        return true;
    }

    void solve(vector<vector<string>> &ans,vector<string> &load,string s, int indx){
        if(indx == s.size()){
            ans.push_back(load);
            return;
        }
        for(int i=indx;i<s.size();i++){
            if(isvalid(i,indx,s)){
                load.push_back(s.substr(indx,i-indx+1));
                solve(ans,load,s,i+1);
                load.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> load;
        solve(ans,load,s,0);
        return ans;
    }
};