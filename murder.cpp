#include<bits/stdc++.h>
using namespace std;

long long merge(long long arr[], int start, int mid, int end){
    int i = start, j = mid, k=0; long long sum = 0;
    int temp[end-start+1];
    while(i<mid && j<=end){
        if(arr[i]<arr[j]){
            sum += arr[i]*(end-j+1);
            temp[k++] = arr[i++];
        }
        else{
            temp[k++] = arr[j++];
        }
    }

    while(i<mid){
        temp[k++] = arr[i++];
    }

    while(j<=end){
        temp[k++] = arr[j++];
    }
    for(int i=start,k=0;i<=end;i++,k++){
        arr[i] = temp[k];
    }

    return sum;
}

long long mergeSort(long long arr[], int start, int end){

    long long total_sum = 0;
    if(end>start){
        long long sum, sumLeft,sumRight;
        int mid = (start+end)/2;
        
        sumLeft = mergeSort(arr, start, mid);
        sumRight = mergeSort(arr, mid+1, end);
        sum = merge(arr, start, mid+1, end);
        return sumLeft+sumRight+sum;
    }
    return total_sum;
    
}

long long getSum(long long *arr, int n)
{
    //Write your code here
    long long ans = mergeSort(arr, 0, n-1);
    return ans;
}

int main()
{
    int t;
    cin >>t;
    while(t--){
        int n;
        cin>>n;
        long long* arr = new long long[n];

        for(int i = 0; i < n; ++i)
        {
            cin >> arr[i];
        }

        cout << getSum(arr, n)<<endl;
    }
    

}