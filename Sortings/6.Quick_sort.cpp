#include<bits/stdc++.h>
using namespace std;


int partition(int a[],int l,int r){
    int pivot = a[r-1];
    int i = l-1;
    for(int j = l;j<r;j++){
        if(a[j]<pivot){
            i++;
            swap(a[i],a[j]);
        }
    }
    i++;
    swap(a[i],a[r-1]);
    return i;
}

void qsort(int a[],int l,int r){
    if(l>=r){
        return ;
    }
    int p = partition(a,l,r);
    qsort(a,l,p-1);
    qsort(a,p+1,r);
}


int main(){
    int a[] ={43,2,34,21,10,45,100};
    qsort(a,0,7);
    for(int i=0;i<7;i++){
        cout<<a[i]<<" ";
    }
    return 0;
}