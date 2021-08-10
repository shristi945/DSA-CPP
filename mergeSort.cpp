#include <iostream>
using namespace std;

void merge(int input[], int start, int mid, int end){
    int temp[end-start+1];
    int i=start, j = mid, k=0;
    while(i<mid && j<=end){
        if(input[i]<=input[j]){
            temp[k++] = input[i++];
        }
        else{
            temp[k++] = input[j++];
        }
    }
    while(i<mid){
        temp[k++] = input[i++];
    }
    while(j<=end){
        temp[k++] = input[j++];
    }
    for(int i=start, k=0; i<=end;i++, k++){
        input[i] = temp[k];
    }
}

void mergeSortHelper(int input[], int start, int end){
    if(start<end){
        int mid = start+(end-start)/2;
        mergeSortHelper(input, start, mid);
        mergeSortHelper(input, mid+1, end);
        merge(input, start, mid+1, end);
    }
}

void mergeSort(int input[], int size){
	// Write your code here
    mergeSortHelper(input, 0, size-1);
    
    
}


int main() {
  int length;
  cin >> length;
  int* input = new int[length];
  for(int i=0; i < length; i++)
    cin >> input[i];
  mergeSort(input, length);
  for(int i = 0; i < length; i++) {
    cout << input[i] << " ";
  }
}