#include<iostream>
using namespace std;
bool isSorted(int a[], int size){
    if ((size == 0) ||  (size == 1)){
        return true;
    }
    if (a[0] >a[1]){
        return false;
    }
    bool smallOutput = isSorted(a+1, size-1);
    return smallOutput;
}

int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>> arr[i];
    }
    bool output1 = isSorted(arr, n);
    cout << output1;
}

