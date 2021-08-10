#include<bits/stdc++.h>
using namespace std;
int chalkReplacer(vector<int>& chalk, int k) {
        int sum = accumulate(chalk.begin(),chalk.end(),0);
        if(k%sum == 0){
            return 0;
        }
        int x = k/sum;
        int nk = k-(sum*x);
        int ans = -1;
        // cout<<"nk"<<nk<<endl;
        for(int i=0;i<chalk.size();i++){
            if(nk>=chalk[i]){
                nk = nk-chalk[i];
                if(nk==0){
                    if(i!=chalk.size()-1){
                        ans = i+1;
                        break;
                    }
                    else{
                        ans = 0;
                        break;
                    }
                }
            }
            else{
                ans=i;
                break;
            }
        
        }
    return ans;  
}

int main(){

    vector<int>chalk{3,4,1,2};
    int k=25;

    cout<<chalkReplacer(chalk, k);

    return 0;
}