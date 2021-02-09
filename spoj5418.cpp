/*
Problem Description
After trying hard for many years, Victor has finally received a pilot license. 
To have a celebration, he intends to buy himself an airplane and fly around the world.
There are n countries on the earth, which are numbered from 1 to n. 
They are connected by m undirected flights, detailedly the i-th flight connects the ui-th and the vi-th country, 
and it will cost Victor's airplane wi L fuel if Victor flies through it.
And it is possible for him to fly to every country from the first country.
Victor now is at the country whose number is 1,
he wants to know the minimal amount of fuel for him to visit every country at least once and finally return to the first country.'
Input
The first line of the input contains an integer T, denoting the number of test cases.
In every test case, there are two integers n and m in the first line, denoting the number of the countries and the number of the flights.
Then there are m lines, each line contains three integers ui, vi and wi, describing a flight.
1≤T≤20.
1≤n≤16.
1≤m≤100000.
1≤wi≤100.
1≤ui,vi≤n.
Output
Your program should print T lines : the i-th of these should contain a single integer, 
denoting the minimal amount of fuel for Victor to finish the travel.
Sample Input
1
3 2
1 2 2
1 3 3
Sample Output
10


Ideas: s represents a collection that has passed the city, v represents now in the city. Defined dp [s] [v] starting from v access to all the remaining cities,
then return to the starting point of the shortest path required.
MP [i] [j] denotes the shortest i to j.
VThe set of all vertices. Initialization dp [V] [0] = 0
State transition equation:
dp[s][v]=min(dp[s|{u}][u] +mp[u][v]) (uDoes not belong s)
Two ways: memory search recursive compressed state and DP

*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

#define inf 0x3f3f3f3f
#define M 20
int d[M][M];
int dp[1 << M][M];
int n, m;

void floyd() {
    
    for(int k = 0; k < n; ++k) {
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }

}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    cin >> n >> m;
    while (t--) {
        
        
        for(int i = 0; i < M; ++i) {
            fill(d[i], d[i] + n, inf);
        }

        for(int i = 1; i <= m; ++i) {
            int a, b, c;
            cin >> a >> b >> c;
            --a; --b;
            d[a][b] = min(d[a][b], c);
            d[b][a] = d[a][b];
        }
        
        for(int i = 0; i < n; ++i) d[i][i] = 0;
        floyd(); 

        for(int j = 0; j < (1 << n); ++j) fill(dp[j], dp[j] + n, inf);

        dp[(1 << n)-1][0] = 0;

        for(int s = (1 << n) - 2; ~s; s--) {
            for(int v = 0; v < n; ++v) {
                for(int u = 0; u < n; ++u) {
                    if (!(s & (1 << u))) {
                        dp[s][v] = min(dp[s][v], dp[s | (1 << u)][u] + d[v][u]);
                    }
                }
            }
        }
        cout << dp[0][0] << endl; 
    }

    return 0;
}
