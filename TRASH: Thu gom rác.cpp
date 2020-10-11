#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;



int main() {
    
    int n, t;
    cin >> n >> t; 
    vector<int> a(n);
    
    long int cnt(0);
    
    for(int& x : a) {
        cin >> x;
    }

    for(int i = 0; i < n; ++i) {
        long int sum = 0;
        for (int j = i; j < n; ++j){
            sum += a[j];
            if (sum <= t) ++cnt;
            else break;
        }
        
    }
    cout << cnt << "\n";
    
    return 0;
}
