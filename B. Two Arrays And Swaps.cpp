#include <bits/stdc++.h>

using namespace std;

int a[40];
int b[40];



int main(void) {

	int t;
	cin >> t;

	int n, k;

	while (t--) {
		cin >> n >> k;

		for (int i = 1; i <= n; ++i) cin >> a[i];
		for (int i = 1; i <= n; ++i) cin >> b[i];

		sort (a + 1, a + 1 + n);
		sort (b + 1, b + 1 + n);

		for (int i = 1; i <= k; ++i) {
			if (a[i] > b[n-i+1]) break;
			else swap(a[i], b[n-i+1]);
		} 

		int res(0);
		cout << accumulate(a+1, a+1+n, res) << "\n";
	}

	return 0;
}
