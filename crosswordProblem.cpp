#include <iostream>
#include<bits/stdc++.h>
using namespace std;

bool isValidVertical(char cross[10][10], vector<string>words, int index, int col){
    
}

bool setVertical(vector<bool>helper){

}
bool resetVertical(vector<bool>helper){

}

bool crossword(char cross[10][10], vector<string>words, int index){

    for(int r=0;r<10;r++){
        for(int c=0;c<10;c++){
            if(cross[r][c] == '-' || cross[r][c] == words[index][0]){
                if(isValidVertical(cross, words,index,c)){
                    vector<bool>helper;
                    setVertical(helper);
                    crossword(cross, words, index+1);
                    resetVertical(helper);
            }
        }
    }
}


int main(){

    char cross[10][10];
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            cin>>cross[i][j];
        }
    }
    int n;
    cin>>n;
    vector<string> words(n);
    for(int i=0;i<n;i++){
        cin>>words[i];
    }
    crossword(cross, words, 0);
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            cout<<cross[i][j];
        }
    }


    return 0;
}