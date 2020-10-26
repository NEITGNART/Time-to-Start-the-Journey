#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define vi vector<int> 

int BinarySearch(vi a, int n , int key) {

	// code 1 :

	int low = 0;
	int high = n - 1;

	while (low <= high) {

		int mid = (low + high) / 2;
		if (a[mid] == key) return mid;
		else if (a[mid] > key)  high = mid - 1;
		else low = mid + 1;
	}
	// if not find the key in array a and then return -1

	// code 2:

	int k = 0;
	for (int b = n / 2; b >= 1; b /= 2) {
		while (k + b < n && a[k + b] <= key) k += b;
	}
	if (a[k]== key) return k;
	
	return -1;
}

auto init = [](auto& a) {
	int n = a.size();
	for (int i = 0; i < n; ++i) a[i] = i + 1;
};


auto BinarySearch_Recursion = [](auto& a, int left, int right, int key) ->int {

	if (left >= right) return -1;
	
	int mid = (left + right) / 2;
	if (a[mid] == key) return mid;
	else if (a[mid] > key) BinarySearch_Recursion(a, left, mid - 1, key);
	else BinarySearch_Recursion(a, mid + 1, right, key);
};	

int sumOfSquares(int n) {
	if (n == 1) return 1;

	return n * n + sumOfSquares(n - 1);
}

int GCD (int a, int b) {
	if (b == 0) return a;
	return GCD(b, a % b);
}

int gcd(int a, int b) {
	while (b != 0) {
		int r = a % b;
		a = b;
		b = r;
	}
	return a;
} 


bool isPalindrome(string a, int n) {
	int mid = (n-1) / 2;
	static int num = n;
	if (n <= 0) return false;
	if (mid == 0)  return a[mid] == a[num];
	if (a[mid] != a[num - mid]) return false;
	isPalindrome(a, n - 2);
	return true;
}

int Factorial(int n) {
	if (n == 1) return 1;
	return n * Factorial(n - 1);
}

int countDigit(int a) {
	if (a == 0) return 0;
	return 1 + countDigit(a / 10);
}

int Fib(int n) {
	if (n == 0 || n == 1) return 1;
	return Fib(n - 1) + Fib(n - 2);
}

int main(void) {

	int n = 7;
	int m = 9;

	cout << GCD(20, 600) << endl;
	cout << gcd(20, 600) << endl;

	cout << Factorial(6);
	return 0;
}
