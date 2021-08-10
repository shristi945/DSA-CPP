#include<bits/stdc++.h>
using namespace std;

pair<int,int> pariOfPrimes(int k){
	// Write your code here.
    vector<int> prime;
    prime.push_back(2);
    for(int i=3;i<=k;i++){
        int num=i; int j;
        for(j=2; j<num;j++){
            if(num%j==0){
                break;
            }
        }
        if(j==num) prime.push_back(num);
    }
    pair<int, int> res;
    int i=0, j=prime.size()-1;
    while(i<=j){
        if(prime[i]+prime[j]==k){
            res = make_pair(prime[i],prime[j]);
            return res;
        }
        else if(prime[i]+prime[j]<k) i++;
        else j--;
    }
    return res;
}

int main(){
    int k;
    cin>>k;
    pair<int, int> p = pariOfPrimes(k);
    cout<<p.first<< " "<<p.second<<endl;
    // vector<int> r = getPrime(k);
    // for(int i=0;i<r.size();i++){
    //     cout<<r[i]<<endl;
    // }
    return 0;
}