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

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>

using namespace std;

#define vi vector<int>

struct Examinee
{
	string id;
	string name;
	float math, literature, physic, chemistry, biology, history, geography, civic_education, natural_science,
		social_science, foreign_language;
	string note;
	string provincial;
};


void readExamineeList(vector<Examinee>& list, string name) {

	ifstream fin(name.c_str());
	if (fin.fail()) return;

	string buffer;
	getline(fin, buffer);
	
		while (fin.good()) {
		Examinee object;

		string id;
		getline(fin, id, ','); 
		if (id.empty()) object.id = "";
		else object.id = id;
		cout << id << endl;


		string name;
		getline(fin, name, ',');
		if (name.empty()) object.name = "";
		else object.name = name;
		cout << name << endl;
			
		string math;
		getline(fin, math, ','); 
		
		if (math.empty()) object.math = 0;
		else object.math = stof(math);
		cout << math << endl;

		string literature;
		getline(fin, literature, ','); 
		if (literature.empty()) object.literature = 0;
		else object.literature = stof(literature);

		cout << literature << endl;

		string physics;
		getline(fin, physics, ',');
		if (physics.empty()) object.physic = 0;
		else object.physic = stof(physics);
		cout << physics << endl;
		string chemistry;
		getline(fin, chemistry, ','); 
		if (chemistry.empty()) object.chemistry = 0;
		else object.chemistry= stof(chemistry);
		cout << chemistry << endl;
		string bio;
		getline(fin, bio, ','); 
		if (bio.empty()) object.biology = 0;
		else object.biology = stof(bio);
		cout << bio << endl;
		string history;
		getline(fin, history, ','); 
		if (history.empty()) object.history = 0;
		else object.history = stof(history);
		cout << history << endl;
		string geo;
		getline(fin, geo, ','); 
		if (history.empty()) object.geography = 0;
		else object.geography = stof(geo);
		cout << geo << endl;
		string civic_education;
		getline(fin, civic_education, ','); 
		if (civic_education.empty()) object.civic_education = 0;
		else object.civic_education = stof(civic_education);
		cout << civic_education << endl;
		string natural;
		getline(fin, natural, ','); 
		if (natural.empty()) object.natural_science = 0;
		else object.natural_science = stof(natural);
		cout << natural << endl;
		string social;

		getline(fin, social, ',');
		if (social.empty()) object.social_science = 0;
		else object.social_science = stof(social);
		cout << social << endl;

		string foreign;
		getline(fin, foreign, ','); 
		if (foreign.empty()) object.foreign_language = 0;
		else object.foreign_language = stof(foreign);
		cout << foreign << endl;
		string note;
		getline(fin, note, ','); 
		if (note.empty()) object.note = "";
		else object.note = (note);
		cout << note << endl;
		string provincial;
		getline(fin, provincial); 
		if (provincial.empty()) object.provincial = "";
		else object.note = (provincial);

		cout << provincial << endl << endl << endl;
		cout << "size: " << list.size() << endl;
		list.push_back(object);
	}
	
}



int main(void) {

	vector<Examinee> list;

	string name = "C:/Users/Administrator/source/repos/For_Fun/For_Fun/data.txt";
	readExamineeList(list, name);

	cout << list.size();
	return 0;

}
