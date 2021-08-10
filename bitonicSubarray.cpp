#include<bits/stdc++.h>
using namespace std;

int bitonic(int *arr, int n){
    int *dpInc = new int[n];
    int *dpDec = new int[n];
    dpInc[0] = 1;
    for(int i=1;i<n;i++){
        int including_max = 1;
        for(int j=i-1;j>=0;j--){
            if(arr[j]<arr[i]){
                including_max = max(1+dpInc[j],including_max);
            }
        }
        dpInc[i] = including_max;
    }

    cout<<"dpInc"<<endl;
    for(int i=0;i<n;i++){
        cout<<dpInc[i]<<" ";
    }
    cout<<endl;

    dpDec[n-1] = 1;
    for(int i=n-2;i>=0;i--){
        int including_max=1;
        for(int j=i+1;j<=n-1;j++){
            if(arr[i]>arr[j]){
                including_max = max(1+dpDec[j], including_max);
            }
        }
        dpDec[i] = including_max;
    }

    cout<<"dpDec"<<endl;
    for(int i=0;i<n;i++){
        cout<<dpDec[i]<<" ";
    }
    cout<<endl;
    
    int best=0;
    for(int i=0;i<n;i++){
        dpInc[i] = dpInc[i]+dpDec[i];
        if(best<dpInc[i]){
            best = dpInc[i];
        }
    }
    
    delete [] dpInc;
    delete [] dpDec;
    return best-1;
    // return 0;
}

int main() {

    int n = 2;
    // cin>>n;
    int *arr = new int[n]{1,5};
    // for(int i=0;i<n;i++){
    //     cin>>arr[i];
    // }
    cout<<bitonic(arr, n);

}