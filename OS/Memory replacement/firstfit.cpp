#include<bits/stdc++.h>
using namespace std;
void first_fit(int *blocksize,int n,int *processsize,int m){
    int allocation[100];
    for(int i=0;i<100;i++){
        allocation[i]=-1;
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(blocksize[j]>=processsize[i]){
                blocksize[j] -= processsize[i];
                allocation[i] = j;
                break;
            }
        }
    }
    cout << "\nProcess No.\tProcess Size\tBlock no.\n";
    for(int i=0;i<m;i++){
        cout << " " << i+1 << "\t\t"
			<< processsize[i] << "\t\t";
		if (allocation[i] != -1)
			cout << allocation[i] + 1;
		else
			cout << "Not Allocated";
		cout << endl;
    }
}


int main()
{
    cout<<"Enter the number of partionions :-";
    int n,m;
    cin>>n;
    int blocksize[n];
    cout<<"Enter the partionions block size \n ";
    for(int i=0;i<n;i++){
        cin>>blocksize[i];
    }
    cout<<"Enter the process required\n ";
    cin>>m;
    int processsize[m];
    cout<<"Enter hte process in array\n";
    for(int i=0;i<m;i++){
        cin>>processsize[i];
    }
    first_fit(blocksize,n,processsize,m);
    
    return 0;
}
