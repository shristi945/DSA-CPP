#include <iostream>
#include<bits/stdc++.h>
using namespace std;
// int stringSubsequence(string s, string output[]){
//     if(s.empty()){
//         output[0] = "";
//         return 1;
//     }
//     string smallString = s.substr(1);
//     int smallOutputSize = stringSubsequence(smallString, output);
//     for(int i=0;i<smallOutputSize; i++){
//         output[i+smallOutputSize] = s[0] + output[i];
//     }
//     return 2*smallOutputSize;
// }

int main(){
    // string s = "abcd";
    string* output {new string[3]{"a","b","c"}};
    string* newOutput = new string[1000];
    int k=0;
    for(int j=0;j<3;j++){
        for(int i=0;i<3;i++){
            newOutput[k++] = output[i];
        }
    }
    for(int i=0;i<9;i++){
        cout<<newOutput[i]<<" "<<endl;
    }
    // int count = stringSubsequence(s,output);
    // for(int i=0; i<count;i++){
    //     cout<<output[i]<<endl;
    // }
    return 0;
}