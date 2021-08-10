#include<bits/stdc++.h>
using namespace std;



vector<int> getLps(string p){
    int m=p.length();
    vector<int>lps(m);
    lps[0]=0;
    int j=0,i=j+1;
    while(i<m && j>=0){
        if(p[i]==p[j]){
            lps[i] = j+1;
            j++;i++;
        }
        else{
            if(j==0){
                lps[i]=0;i++;
            }
            else{
                j = lps[j-1];
            }
            
        }        
    }
    return lps;
}

bool isMatching(string s, string p){


    int n = s.length();
    int m = p.length();

    vector<int>lps = getLps(p);
    int i=0,j=0;
    while(i<n && j<m){
        if(s[i]==p[j]){
            i++;j++;
        }
        else{
            if(j!=0){
                j = lps[j-1];
            }
            else{
                i++;
            }
        }
    }
    if(j==m) return true;
    return false;

}


int main(){

    string s,p;
    cin>>s>>p;

    cout<<isMatching(s,p)<<endl;


    return 0;
}
