#include<bits/stdc++.h>

using namespace std;


int main(){

    string s;
    s = "abbabbabbc";
    int n=  s.length();
    int maxlen = 1;
    for(int i=0;i<n;i++){

        int left = i, right = i;
        int currlen ;
        while(s[left]==s[right] && left>=0 && right<n){
            currlen = right-left+1;
            maxlen = max(maxlen, currlen);
            left--;right++;
        }

        if(left>=0 && right<n && s[i]==s[i+1]){
            left = i;right = i+1;
            while(s[left]==s[right] && left>=0 && right<n){
                currlen = right-left+1;
                maxlen = max(maxlen, currlen);
                left--;right++;
            }
            
        }
        
    }

    cout<<maxlen;
    return 0;
}