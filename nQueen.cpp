#include<iostream>
#include<vector>
#include<string>
using namespace std;
class solution{
public:
	bool isSafe(const vector<string> &board, int row, int col, int n){
//		vertical check above (0 to row -1;
		for(int i =0; i < row; i++){
			if(board[i][col] == 'Q'){
				return false;
			}
		}
//		left diagonal (starting at row - 1; col - 1
        for(int i = row -1, j = col -1; i >= 0 && j >= 0; i--, j--){
        	if(board[i][j] == 'Q'){
        		return false;
			}
		}
//		right diagonal check (starting ar row -1 , col +1
		for(int i = row -1, j = col+1; i >= 0 && j < n; i--, j++){
			if(board[i][j] == 'Q') return false;
		}
    return true;
	}
	void nQueen(vector<string> &board, int row, int n, vector<vector<string>> &ans){
		if(row == n){
				ans.push_back(board); // direct push
				return;
		}
		for(int j =0; j<n; j++){
			if(isSafe(board, row,j,n)){
				board[row][j] ='Q';
				nQueen(board, row +1, n, ans);
				board[row][j] ='.'; // backtrack
			}
		}
	}
	vector<vector<string>> solvenqueen(int n)
	{
		vector<string> board(n, string(n, '.'));
		vector<vector<string>> ans;
		nQueen(board, 0, n, ans);
		return ans;
	}
	
};
int main() {
    solution help;
    auto result = help.solvenqueen(4);
    cout << "Solutions: " << result.size() << "\n";
    for (auto b : result) for (auto r : b) cout << r << "\n";
}
