
#include<bits/stdc++.h>
using namespace std;

int main(){
    string coordinates = "h8";
    unordered_map<char,int> m;
    m['a']=0; 
    m['b']=1; 
    m['c']=2; 
    m['d']=3;
    m['e']=4;
    m['f']=5;
    m['g']=6;
    m['h']=7;
    bool color = false;
    int v[8][8];
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            v[i][j] = color;
            color = !color;
            
        }
        color = !color;
    }
    int x = m[coordinates[0]];
    int y= ((int)coordinates[1]-48)-1;
    
    cout<<v[x][y];



}