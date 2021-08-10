#include <bits/stdc++.h>

using namespace std;
#define M 1000000007
int substrings(string n) {

    long long totalSum = n[0]-'0';
    long long lastvalue = n[0]-'0';

    for(int i=1;i<n.length();i++){
        lastvalue = lastvalue*10 + ((n[i]-'0')*(i+1));
        lastvalue = lastvalue%M;
        totalSum = (totalSum + lastvalue)%M;
    }
    return totalSum;

}

int main()
{

    string n;
    n="123";

    int result = substrings(n);

    cout << result;


    return 0;
}
