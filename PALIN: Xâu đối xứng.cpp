#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

vector<int> f;

void manacher(const string &s) {
    string a;
    for (char c: s) a += '.', a += c;
    a += '.';
    int n = a.size();
    f.resize(n);
    int r = 0, c = 0;
    for (int i=0; i<n; i++) {
        f[i] = i<r? min(r-i, f[c-(i-c)]) : 0;
        while (a[i-f[i]-1] == a[i+f[i]+1]) f[i]++;
        if (i+f[i] > r) {
            r = i + f[i];
            c = i;
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    
    string s;
    cin >> s;
    manacher(s);
    sort(f.begin(), f.end());
    
    int t;
    cin >> t;
    int x, max = *max_element(f.begin(), f.end());
    
    while (t--) {
        cin >> x;
        if (binary_search(f.begin(), f.end(), x)) cout << 1 << endl;
        else cout << "0\n";
    }
    
}
