#include <iostream>
#include <iomanip>

using namespace std;

int grid[16][16];
int a[16][16];


int main(void) {

    int N  = 16;

    int start = 1;

    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < N; ++j) {
            grid[i][j] = start++;
        }
    }

    start = 1;
   
    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < N; ++j)  {
             cout << setw(4) <<  grid[i][j] << ' ';
        }
        cout << '\n';
    }

    

    cout << "Spriral enumerate: \n";

    int T = 0, B = N - 1, L = 0, R = N - 1;
    
    int dir = 0;
    int x, y = 0;
    
    while (T <= B && L <= R) {
        if (dir == 0) {
            for(int i = T; i <= R; ++i) {
                // grid[T][i] << ' ';
                a[T][i] = start++;
            }
            //cout << endl;
            T++;
        } else if (dir == 1) {
            for(int i = T; i <= B; ++i) {
                //cout << grid[i][R] << " ";
                a[i][R] = start++;
            }
           // cout << endl;
            R--;
        }
        else if (dir == 2) {
            for(int i = R; i >= L; --i) {
                //cout << grid[B][i] << ' ';
                a[B][i] = start++;
            }
            //cout << endl;
            B--;
        } else if (dir == 3) {
            for(int i = B; i >= T; --i) {
                //cout << grid[i][L] << ' ';
                a[i][L] = start++;
            }
            //cout << endl;
            L++;
        }
        dir = (dir + 1) % 4;
    }

    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < N; ++j)  {
            cout << setw(4) << a[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}

// ===================================================== Genius =========================================

#include <iostream>
#include <iomanip>
#include <array>

using namespace std;

int grid[16][16];
int a[16][16];
array<int, 4> dx{0, 1, 0, -1};
array<int, 4> dy{1, 0, -1, 0};

int main(void) {

    
    int N{4}, M{4};
    int start = 1;
    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < M; ++j) {
            grid[i][j] = start++;
        }
    }

    int n = N * M;
    
    int x{0}, y{0};
    int dir = 0;
    for(int k = 0; k < n; ++k) {
        cout << grid[x][y] << ' ';
        grid[x][y] = 0;
        int i = x + dx[dir], j = y + dy[dir];
        if (i < 0 || i >= N || j < 0 || j >= M || !grid[i][j]) {
            dir = (dir + 1) % 4;
            i = x + dx[dir], j = y + dy[dir];
            cout << endl;
        }
        x = i;
        y = j;
    }

    return 0;
}
