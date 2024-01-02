#include <bits/stdc++.h>
using namespace std;

void fun(vector<int> &a,vector<int> &ref,int indx=0){
    if(a.size()==indx){
        return ;
    }
        int dumm = a[indx];
        fun(a,ref,indx + 1);
        ref.push_back(dumm);
}

void display(vector<int> &ref){
    for(auto it:ref){
        cout<<it<<" ";
    }
}

int main()
{
    vector<int> a= {1,2,3,4,5};
    vector<int> ref;
    fun(a,ref);
    display(ref);

    return 0;
}
