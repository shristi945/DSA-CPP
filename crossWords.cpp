#include<bits/stdc++.h>
using namespace std;
int ways = 0;
void printMatrix(vector<string>& matrix, int n)
{
    for (int i = 0; i < n; i++)
        for(int j=0;j<n;j++){
            cout<<matrix[i][j];
        }
    cout<<endl;
}

vector<string> checkHorizontal(int x, int y,
                               vector<string> matrix,
                               string currentWord)
{
    int n = currentWord.length();
  
    for (int i = 0; i < n; i++) {
        if (matrix[x][y + i] == '-' || 
            matrix[x][y + i] == currentWord[i]) {
            matrix[x][y + i] = currentWord[i];
        }
        else {
  
            // this shows that word cannot 
            // be placed horizontally
            matrix[0][0] = '+';
            return matrix;
        }
    }
  
    return matrix;
}

vector<string> checkVertical(int x, int y,
                             vector<string> matrix,
                             string currentWord)
{
    int n = currentWord.length();
  
    for (int i = 0; i < n; i++) {
        if (matrix[x + i][y] == '-' || 
            matrix[x + i][y] == currentWord[i]) {
            matrix[x + i][y] = currentWord[i];
        }
        else {
  
            // this shows that word
            // cannot be placed vertically
            matrix[0][0] = '+';
            return matrix;
        }
    }
    return matrix;
}

void solvePuzzle(vector<string>& words,
                 vector<string> matrix,
                 int index, int n)
{
    if (index < words.size()) {
        string currentWord = words[index];
        int maxLen = n - currentWord.length();
  
        // loop to check the words that can align vertically.
        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= maxLen; j++) {
                vector<string> temp = checkVertical(j, i,
                                        matrix, currentWord);
  
                if (temp[0][0] != '+') {
                    solvePuzzle(words, temp, index + 1, n);
                }
            }
        }
  
        // loop to check the words that can align horizontally.
        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= maxLen; j++) {
                vector<string> temp = checkHorizontal(i, j,
                                      matrix, currentWord);
  
                if (temp[0][0] != '+') {
                    solvePuzzle(words, temp, index + 1, n);
                }
            }
        }
    }
    else {
        // calling of print function to
        // print the crossword puzzle
        // cout << (ways + 1) << " way to solve the puzzle "
        //      << endl;
        printMatrix(matrix, n);
        cout << endl;
  
        // increase the ways
        ways++;
        return;
    }
}

int main(){
// length of grid
    int n1 = 10;
  
    // matrix to hold the grid of puzzle
    vector<string> matrix;
  
    // take input of puzzle in matrix
    // input of grid of size n1 x n1
	for(int i=0;i<10;i++){
        string line;
        cin>>line;
        matrix.push_back(line);
    }
    string wordslist;
	cin>>wordslist;
	vector <string> words;

	stringstream ss(wordslist);
 	const char delim=';';
    string s;
    while (getline(ss, s, delim)) {
        words.push_back(s);
    }
  
    // initialize the number of ways
    // to solve the puzzle to zero
    ways = 0;
  
    // recursive function to solve the puzzle
    // Here 0 is the initial index of words array
    // n1 is length of grid
    solvePuzzle(words, matrix, 0, n1);
  
    return 0;
}