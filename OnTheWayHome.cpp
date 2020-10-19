#include <bits/stdc++.h>

using namespace std;

int grid[100][100];


// top_down
int Grid(int x, int y) {
	
	
	if (x < 0 || y < 0) return 0;
	else if (grid[x][y] != -1) return grid[x][y];
	if (x == 0 && y == 0 || x == 1 && y == 0 || x == 0 && y == 1) {
		grid[x][y] = 1;
		return 1;
	} 
	else grid[x][y] = Grid(x, y-1) + Grid(x-1, y);
	
	return grid[x][y];
}


int main(void) {
	
	
	// bottom up
	memset(grid, 0, sizeof(grid));
	for (int i = 0; i <= 9; ++i) grid[0][i] = 1;
	for (int j = 0; j <= 6; ++j) grid[j][0] = 1;
	for (int i = 1; i <= 6; ++i) {
		for (int j = 1; j <= 9; ++j) {
			grid[i][j] = grid[i-1][j] + grid[i][j-1];
		}
	}
	
	for (int i = 0; i <= 6; ++i) {
		for (int j = 0; j <= 9; ++j) {
			cout << setw(4) << grid[i][j] << " ";
		}
		cout << endl;
	}
	
	cout << grid[6][9] << endl;
	
	// But dynamic programing is too weak when comparision with mathematics
	// We have formula : Number of way is equal = C(x+y,x)
		
	
	return 0;
}
