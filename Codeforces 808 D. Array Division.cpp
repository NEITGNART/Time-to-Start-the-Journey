#include <bits/stdc++.h>

using namespace std;

static int MAX = 100000 + 10;
int n;
vector<int> a(MAX);
vector<long long > s(MAX);

bool bisearch(int l, int r, long long x) {
	while (l <= r) {
		int mid =  (l + r)  / 2;
		if (s[mid] == x) {
			return true;
		}
		else if (s[mid] > x) r = mid-1;
		else l = mid + 1;
	}
	return false;
}

int main(void) {

	int n;
	cin >> n;
	
	long long sum(0);

	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		s[i+1] = s[i] + a[i];
		sum += a[i];
	}
	
	if (sum & 1) {
		cout << "NO" << endl;
		return 0;
	} else {
		sum = sum >> 1;
		for (int i = 0; i < n; ++i) {
			if (bisearch(i+1, n, sum + a[i]) || bisearch(0, i-1, sum-a[i])){
				cout << "YES" << endl;
				return 0;
			}
		}

	}
	cout << "NO\n";
	return 0;
}

