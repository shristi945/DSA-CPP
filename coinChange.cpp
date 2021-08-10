#include<bits/stdc++.h>
using namespace std;

int coin(int d[], int numD, int n, int**output){
    if(n==0)return 1;
    if(numD==0)return 0;
    if(n<0)return 0;
    if(output[n][numD]>-1){
        return output[n][numD];
    }
    int output1 = coin(d, numD, n-d[0], output);
    int output2  = coin(d+1,numD-1, n, output);
    output[n][numD] = output1+output2;
    return output1+output2;
}
int main()
{

	int numDenominations;
	cin >> numDenominations;
	
	int *denominations = new int[numDenominations];

	for (int i = 0; i < numDenominations; i++)
	{
		cin >> denominations[i];
	}

	int value;
	cin >> value;
    int** A = new int*[value+1];
 
    // dynamically allocate memory of size `N` for each row
    for (int i = 0; i < value+1; i++) {
        A[i] = new int[numDenominations+1];
    }
 
    // assign values to the allocated memory
    for (int i = 0; i < value+1; i++)
    {
        for (int j = 0; j < numDenominations+1; j++) {
            A[i][j] = -1;
        }
    }
	cout << coin(denominations, numDenominations, value,A);

	delete[] denominations;
}