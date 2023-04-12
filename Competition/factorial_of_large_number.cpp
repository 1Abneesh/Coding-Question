//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution {
public:
    vector<int> factorial(int N){
        // code here
        vector<int> res;
        res.push_back(1);
        int siz = 1;
        int c=0;
        int num = 2;
        while(num<=N){
        for(int i=siz-1;i>=0;i--){
            int temp = res[i]*num + c;
            res[i] = temp%10;
            c = temp/10;
        }
        while(c){
            int dum = c%10;
            res.insert(res.begin(),dum);
            c=c/10;
            siz++;
        }
        num++;
        }
        return res;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        Solution ob;
        vector<int> result = ob.factorial(N);
        for (int i = 0; i < result.size(); ++i){
            cout<< result[i];
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends