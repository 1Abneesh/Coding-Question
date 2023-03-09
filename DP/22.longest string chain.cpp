class Solution {
public:
    bool isvalid(string &s1,string &s2){
        if(s1.size() !=s2.size()+1){
            return false;
        }
        int i=0;
        int j=0;
        while(i<s1.size()){
            if(s1[i] == s2[j]){
                i++;
                j++;
            }
            else{
                i++;
            }
        }
        if(i==s1.size() && j==s2.size()){
            return true;
        }
        return false;
    }

    bool static comp(string& s1, string& s2){
        return s1.size() < s2.size();
    }

    int longestStrChain(vector<string>& words) {
        vector<int> dp(words.size(),1);
        int maxi =0;
        sort(words.begin(),words.end(),comp);
        for(auto it:words){
            cout<<it<<" ";
        }
        for(int i=0;i<words.size();i++){
            for(int j=0;j<i;j++){
                if(isvalid(words[i],words[j])){
                    dp[i] = max(dp[i],1+dp[j]);
                }
            }
            maxi = max(dp[i],maxi);
        }

        return maxi;
    }
};