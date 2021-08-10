#include<bits/stdc++.h>
using namespace std;
void swap(vector<int>&arr, int p, int j){
    int temp = arr[p];
    arr[p] = arr[j];
    arr[j] = temp;
}

void rotate(vector<int>&arr, int p, int j){
    int temp = arr[p];
    arr[p] = arr[j];
    arr[j] = temp;
}

int main(){

    vector<int>arr{-5, -2, 5, 2, 4, 7, 1, 8, 0, -8};
    int p=-1;int count =0;
    for(int i=0;i<arr.size();i++){
        if(arr[i]<0){
            count++;
            continue;
        }
        else{
            p = i;
            int j=i+1;
            while(j<arr.size() && arr[j]>=0){
                j++;
            }
            if(j<arr.size() && arr[j]<0){
                count++;
                swap(arr, p, j);
                p++;
            }
        }

    }

    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
    int neg = 1, pos = count;
    while(neg<pos){
        swap(arr, neg, pos);
        neg +=2;
        pos++;
    }

    cout<<"final"<<endl;
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }


    return 0;
}