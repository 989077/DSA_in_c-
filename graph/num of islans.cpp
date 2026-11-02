#include<iostream>
#include<vector>
using namespace std;

class solution{
	public:
		void dsf(int i, int j, vector<vector<bool>> &vis, vector<vector<char>>& grid
		, int n , int m){
			if( i < 0 || j<0 || i >= n || j >= m || vis[i][j] ||  grid[i][j] != '1'){
				return;
			}
			vis[i][j] = true;
			
			dsf(i-1, j, vis, grid, n , m);
			dsf(i, j+1, vis, grid, n, m);
			dsf(i+1, j, vis, grid, n, m);
			dsf(i, j-1, vis, grid, n, m);
		}
		
		int numislands(vector<vector<char>>& grid){
			int islands = 0;
			int n = grid.size();
			int m = grid[0].size();
			vector<vector<bool>> vis(n, vector<bool>(m, false));
			for(int i =0; i<n; i++){
			for(int j = 0; j<m; j++){
				if(grid[i][j] == '1' && !vis[i][j]){
					dsf(i, j, vis, grid, n, m);
					islands++;
				}
			}
			}
			return islands;
		}
};

int main(){
	solution s;
	vector<vector<char>> grid = {
        {'1', '1', '1', '1', '0'},
        {'1', '1', '0', '1', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '0', '0', '0'}
    };
    
  cout<<"outpput"<<  s.numislands(grid);
  cout<<endl;
return 0;
}

