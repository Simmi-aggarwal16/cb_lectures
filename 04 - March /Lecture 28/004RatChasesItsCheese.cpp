#include<iostream>

using namespace std;

void printPath(char path[][10], int m, int n) {
	for(int i=0; i<m; i++) {
		for(int j=0; j<n; j++) {
			cout << path[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

void f(char maze[][10], char path[][10], int m, int n, int i, int j) {

	// base case
	if(i == m-1 and j == n-1) {
		// you've reached the destination
		if(maze[i][j] == 'X') {
			// destination is blocked
			return;
		}
		path[i][j] = '1';
		printPath(path, m, n);
		path[i][j] = '0';
		return;
	}

	if(i == -1 or i == m or j == -1 or j == n) {
		return;
	}

	if(maze[i][j] == 'X') {
		// you are at a cell which is blocked
		return;
	}

	// recursive case

	// you are at a cell from where you can move left, right, up or down

	if(path[i][j] == '1') {
		// (i, j)th cell is already part of the path
		return;
	}

	path[i][j] = '1';
	// maze[i][j] = 'X'; // block-cell

	// 1. move left
	f(maze, path, m, n, i, j-1);

	// 2. move right

	f(maze, path, m, n, i, j+1);

	// 3. move up
	f(maze, path, m, n, i-1, j);

	// 4. move down

	f(maze, path, m, n, i+1, j);

	path[i][j] = '0'; // back-tracking
	// maze[i][j] = '0'; // un-block

}

int main() {

	
	char maze[][10] = {"0X00",
					   "000X",
	                   "X0X0",
	                   "X00X",
	                   "XX00"};


	char path[][10] = {"0000",
	                   "0000",
	                   "0000",
	                   "0000",
	                   "0000"};
	int m = 5;
	int n = 4;

	f(maze, path, m, n, 0, 0);

	return 0;
}