#include <bits/stdc++.h>
#include "input.h"

using namespace std;

void fizzBuzz(int n) {
	for (int i = 1; i <= n; i++) {
		if (i % 15 == 0) {
			cout << "FizzBuzz" << endl;
			continue;
		}
		if (i % 3 == 0) {
			cout << "Fizz" << endl;
			continue;
		}
		if (i % 5 == 0) {
			cout << "Buzz" << endl;
			continue;
		}
		cout << i << endl;
	}
}

int main() {
	string n_temp;
	getline(cin, n_temp);

	int n = stoi(ltrim(rtrim(n_temp)));

	fizzBuzz(n);

	return 0;
}