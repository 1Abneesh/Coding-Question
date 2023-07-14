#include<bits/stdc++.h>
using namespace std;

void merge(int *a,int l,int mid,int r){
    int low = l;
    int right = mid+1;
    vector<int> arr;
    while(low<=mid and right<=r){
        if(a[low]<=a[right]){
            arr.push_back(a[low]);
            low ++;
        }
        else{
            arr.push_back(a[right]);
            right ++;
        }
    }
     while(low<=mid){
            arr.push_back(a[low]);
            low ++;
        }
    
    while(right<=r){
            arr.push_back(a[right]);
            right ++;
        }
    
    for (int i = l; i <= r; i++) {
        a[i] = arr[i - l];
    }
}


void merge_sort(int *a,int l,int r){
        if(l>=r){
            return ;
        }
        int mid = (l+r)/2;
        merge_sort(a,l,mid);
        merge_sort(a,mid+1,r);
        merge(a,l,mid,r);
}


int main(){
    int a[] = {12,34,423,1,65,33,3};
    merge_sort(a,0,6);
    for(int i=0;i<7;i++){
        cout<<a[i]<<" ";
    }
    return 0;
}