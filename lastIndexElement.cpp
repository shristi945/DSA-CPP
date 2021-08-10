#include<iostream>
using namespace std;

int allIndexes(int input[], int size, int x, int output[]){
    int input_len = *(&input + 1) - input;
    if (input_len == 0){
        return 0;
    }
    
    int ans = allIndexes(input+1, size-1, x, output);
    if (input[0] == x){
        for(int i =0 ; i<ans;i++){
            output[i] = output[i]+1;
        }
    	int temp[ans];
        for(int i =0; i<ans; i++){
            temp[i] = output[i];
        }
        output[0] = 0;
        for(int i=0; i<ans;i++){
            output[i+1] = temp[i];
        }
        return ans+1;
    }
    else{
        for(int i =0 ; i<ans;i++){
            output[i] = output[i]+1;
        }
        return ans;
    }
}




int main(){
    int n;
    cin >> n;
  
    int *input = new int[n];
    
    for(int i = 0; i < n; i++) {
        cin >> input[i];
    }
    
    int x;
    
    cin >> x;
    
    int *output = new int[n];
    
    int size = allIndexes(input, n, x, output);
    for(int i = 0; i < size; i++) {
        cout << output[i] << " ";
    }
    
    delete [] input;
    
    delete [] output;
    

}