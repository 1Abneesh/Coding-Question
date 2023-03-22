class Solution {
public:
    void solve(int open,int close,vector<string> &a,string &s){
            if((open == 0) && (close == 0)){
                a.push_back(s);
                // return;
            }
            else if(open == close){
                open --;
                s +='(';
                solve(open,close,a,s);
            }
            else if(open<close && open>0){
                int open1 = open;
                open1 --;
                int close1 = close;
                close1 --;
                string s1 = s;
                string s2 = s;
                s1 += '(';
                s2 += ')';
                solve(open1,close,a,s1);
                solve(open,close1,a,s2);
            }
            else if(open==0 && close>0){
                close --;
                s +=')';
                solve(open,close,a,s);
            }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string s ="";
        solve(n,n,ans,s);
        return ans;
    }
};