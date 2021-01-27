#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <numeric>
#include <string>
#include <fstream>


using namespace std;


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int C, S;
    int set = 0;
    while (cin >> C >> S) {

        int dummy = C + C - S;
        int n = C + C;
        vector<int> a(S + dummy, 0);
        for(int i = 0; i < S; ++i) {
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        double A = 1.0 * accumulate(a.begin(), a.end(), 0) / C;
        cout << "Set #" << ++set << endl;
        double imbalance = 0;
        for(int i = 0; i < C; ++i) {
            
            if (a[i] && !a[n-i-1]) {
                cout << " " << i << ": " << a[i] << '\n';
            }
            else if (!a[i] && a[n-i-1]) {
                cout << " " << i << ": " << a[n-i-1] << '\n';
            } 
            else if (a[i] && a[n - i - 1]) {
                 cout << " " << i << ": " << a[i] << ' ' << a[n-i-1] << '\n';
            }
            else {
                cout << " " << i << ":\n";
            }
            double x = a[i] * 1.0 + a[n - 1 - i] * 1.0 - A;
            imbalance += (x >= 0) ? x : -x;
        }
        cout << fixed << setprecision(5) <<  "IMBALANCE = " << imbalance << "\n\n";
    }

    return 0;
}
