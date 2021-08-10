#include<bits/stdc++.h>
using namespace std;
long binaryToDec(string binary){
    int k=0; int tot = 0;
    for(int i=binary.length()-1;i>=0;i--){
        if(binary[i]=='1'){
            tot += pow(2,k);
        }
        k++;
    }
    return tot;
}

int checkNumberOfSetBit(int n){
    int i=0;int count = 0;
    while(i<=8){
        if(n&(1<<i)){
            count++;
        }
        i++;
    }
    return count;
}

int main(){

    vector<pair<int, string>>digit(10);
    digit.push_back(make_pair(0,"01111111"));
    digit.push_back(make_pair(1,"00110000"));
    digit.push_back(make_pair(2,"01101101"));
    digit.push_back(make_pair(3,"01111001"));
    digit.push_back(make_pair(4,"00110011"));
    digit.push_back(make_pair(5,"01011011"));
    digit.push_back(make_pair(6,"00011111"));
    digit.push_back(make_pair(7,"01110000"));
    digit.push_back(make_pair(8,"01111111"));
    digit.push_back(make_pair(9,"01110011"));

    map<int,long>m;
    for(int i=0;i<10;i++){
        m[digit[i].first] = binaryToDec(digit[i].second);
    }
    int input;
    cin>>input;
    int num = input;
    vector<int>arr;
    while(num){
        int rem = num%10;
        arr.push_back(rem);
        num = num/10;
    }
    reverse(arr.begin(), arr.end());
    int total=checkNumberOfSetBit(arr[0]);
    for(int i=1;i<arr.size();i++){
        int xn = arr[i-1]^arr[i];
        total += checkNumberOfSetBit(xn);
    }
    cout<<total;

    return 0;
}