#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;


string s1, s2;
int n, m;


int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> s2;
    s1 = s2;
    reverse(s2.begin(), s2.end());
    cin >> n;
    int t, e;
    m = s1.size()-1;
    while (n--) {
        cin >> t >> e;
        --t; --e;
        if (s1.substr(abs(t), abs(e-t+1)) == s2.substr(abs(m-e), abs(e-t+1)))cout << "1\n";
        else cout << "0\n";
    }
    
    return 0;
}
