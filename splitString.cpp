#include <bits/stdc++.h> 
  
using namespace std; 
  
// Driver code 
int main() 
{ 
  
    // Get the String 
    string str;
    getline(cin,str);
    cout<<"Entered Str: "<< str<<endl;;
    // Initialise the istringstream 
    // with the given string 
    istringstream iss(str); 
  
    // Iterate the istringstream 
    // using do-while loop 
    do { 
        string subs; 
  
        // Get the word from the istringstream 
        iss >> subs; 
  
        // Print the word fetched 
        // from the istringstream 
        cout << subs << endl; 
  
    } while (iss); 
  
    return 0; 
} 