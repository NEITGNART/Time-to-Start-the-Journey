#include<set>
#include<map>
#include<stack>
#include<queue>
#include<vector>
#include<string>
#include<bitset>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<iomanip>
#include<iostream>

#define FOR(i, n) for (int i = 0; i < n; ++i)


using namespace std;


[[noreturn]] void escape() {
    cerr << "Exit" << endl;
    exit(0);
}

const int N = 1e8 + 5;
int n;
vector<int> primes;
bool check[N];

void sieve() {

    memset(check, true, sizeof check);
    for (int i = 2; i < n; ++i) {
        if (check[i]) primes.push_back(i);
        for (int j = 0; j < primes.size() && i * primes[j] < N; ++j) {
            check[i * primes[j]] = false;
            if (i * primes[j] == 0) break;
        }
    }
}
int main() {

    function<void(int, int)> stuff = [](int a, int b) {
        return a + b;
    };

    n = 100;
    sieve();
    for_each(primes.begin(), primes.end(), [](int x) {cout << x << " ";});
    return 0;
}



