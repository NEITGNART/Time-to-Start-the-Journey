#include <bits/stdc++.h>

using namespace std;

int grid[100][100];

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
	
	memset(grid, -1, sizeof(grid));	
	grid[0][0] = 1;
	
	cout << Grid(6, 9) << endl;
	
	for (int i = 0; i <= 6; ++i) {
		for (int j = 0; j <= 9; ++j) {
			cout << setw(4) <<  grid[i][j] << " ";
		}
		cout << endl;
	}
	
	
	return 0;
}
