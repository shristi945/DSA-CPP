#include <iostream>
using namespace std;

int main(){
    
    int n;
    cin>>n;
    string a, b;
    cin>>a>>b;
    int cost = 0;
    for(int i=0;i<a.length();i++){
        if(a[i]==b[i]){
            continue;
        }
        else{
            if((a[i+1]!=b[i+1]) && (a[i+1]!=a[i])){
                cost++; i++;
            }
            else{
                cost++;
            }
        }
    }
    cout<<cost<<endl;
}