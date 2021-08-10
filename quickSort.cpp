#include <iostream>
using namespace std;

void swap(int input[], int a, int b){
    int temp = input[a];
    input[a] = input[b];
    input[b] = temp;
}

int partition(int input[], int si, int ei){
    int smallEleCount = 0, x = input[si];
    for(int i=si+1;i<=ei;i++){
        if(input[i]<=x){
            smallEleCount++;
        }
    }
    int x_index = si+smallEleCount;
    int i = si, j = ei;
    swap(input, si, x_index);
    while(i<j){
        if(input[i]<=x) i++;
        else if(input[j]>x) j--;
        else{
            swap(input, i,j);
            i++; j--;
        }
    }
    return x_index;
}


void quickSortHelper(int input[], int si, int ei){
    if(si>=ei) return;
    int p;
    p = partition(input, si, ei);
    quickSortHelper(input, si, p-1);
    quickSortHelper(input, p+1, ei);
}

void quickSort(int input[], int size) {
  int si = 0, ei=size-1;
  quickSortHelper(input, si, ei);
}


int main(){
    int n;
    cin >> n;
  
    int *input = new int[n];
    
    for(int i = 0; i < n; i++) {
        cin >> input[i];
    }
    quickSort(input, n);
    for(int i = 0; i < n; i++) {
        cout << input[i] << " ";
    }
    

}
