class Solution{   
public:
    void segregate0and1(int arr[], int n) {
        // code here
        int i=-1;
        for(int j=0;j<n;j++){
            if(arr[j] == 0){
                 i++;
                 swap(arr[i],arr[j]);
            }
        }
    }
};