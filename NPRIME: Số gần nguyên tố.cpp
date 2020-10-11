#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <bitset>
#include <cstring>
using namespace std;

const int MN = 1000000+20;
bitset<MN> p;
int n;
inline void Sieve() {
    
    int s = sqrt(MN);
    p.set();
    p[0] = p[1] = false;
    for (int i = 2; i <= s; ++i){
        if (p[i]) {
            for (int j = i*i; j <= MN; j +=i) {
                p[j] = 0;
            }
        }
    }
    
    
}


int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    Sieve();
    cin >> n;
    int x;
    while (n--){
        cin >> x;
        if (x == 0) cout << 1 << "\n";
         else if (p[x-1]|| p[x] || p[x+1]) cout << 1 << "\n";
        else cout << 0 << "\n";
    }
    
    return 0;
}
