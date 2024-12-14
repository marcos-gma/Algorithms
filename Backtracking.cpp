#include <bits/stdc++.h>
#define endl "\n"
#define ll long long

using namespace std;

vector<bool> columns(8,false), lines(8,false), diag1(15,false), diag2(15,false);

int sum = 0;

void backtracking(int row, vector<string> board){
    if (row == 8){
        sum++;
        return;
    }
    
    for(int col=0; col < 8; col++){
        if(board[row][col] == '.' and !columns[col] and !diag1[row-col+7] and !diag2[row+col]){
            columns[col] = true;
            diag1[row-col+7] = true;
            diag2[row+col] = true;
            
            backtracking(row+1,board);
            
            columns[col] = false;
            diag1[row-col+7] = false;
            diag2[row+col] = false;
        }
    }
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	vector<string> board;
	
	string line;

    for(int i=0; i < 8; i++){
        cin >> line;
        board.push_back(line);
    }
    
    backtracking(0,board);
    
    cout << sum << endl;
    
  
	return 0;
}
