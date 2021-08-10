#include<bits/stdc++.h>
using namespace std;

int countConsistentStrings(string allowed, vector<string>& words) {
        unordered_map<char,int> allowed_map;
        for(char c='a';c<='z';c++){
            allowed_map[c] = 0;
        }
        for(char c:allowed){
            allowed_map[c]++;
        }
        // unordered_map<char,int>::iterator it;
        int total_count=0;
        unordered_map<char,int> word_map;
        for(int i=0;i<words.size();i++){
            bool flag=false; int count_word=0;
            for(char c='a';c<='z';c++){
                word_map[c] = 0;
            }
            for(char c:words[i]){
                word_map[c]++;
            }
            for(char c='a';c<='z';c++){
                if(allowed_map[c]>0 && word_map[c]>0){
                    continue;
                }
                else if(word_map[c]>0 && allowed_map[c]==0){
                    flag = true;break;
                }
            }
            if(!flag)total_count++;
        }
        
        return total_count;
}

int main(){

    string allowed ="abc";
    vector<string>words{"a","b","c","ab","ac","bc","abc"};


//     "abc"
// ["a","b","c","ab","ac","bc","abc"]
// "cad"
// ["cc","acd","b","ba","bac","bad","ac","d"]

    cout<<countConsistentStrings(allowed, words);

    return 0;
}
