#include <iostream>
#include <string>

using namespace std;

int main(void) {
	
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	char c;
	int tmp = 0;
	while (~(c = getchar())) {
		if (c == '"' ) {
			if (tmp == 0) {
				cout << "``";
				tmp = 1;
			}
			else if (tmp == 1) {
				cout << "''";
				tmp = 0;
			}
		}
		else cout << c;
	
	}
	
	return 0;
}
