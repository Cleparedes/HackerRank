#include <bits/stdc++.h>
#include "input.h"

using namespace std;

void plusMinus(vector<int> arr) {
	int n = arr.size();
	float p = 0, m = 0, z = 0;
	for (int i = 0; i < n; i++) {
		if (arr[i] > 0) p++;
		else {
			if (arr[i] < 0) m++;
			else z++;
		}
	}
	cout.precision(6);
	cout << fixed;
	cout << p/n << endl;
	cout << m/n << endl;
	cout << z/n << endl;
}

int main() {
	string n_temp;
	getline(cin, n_temp);

	int n = stoi(ltrim(rtrim(n_temp)));

	string arr_temp_temp;
	getline(cin, arr_temp_temp);

	vector<string> arr_temp = split(rtrim(arr_temp_temp));

	vector<int> arr(n);

	for (int i = 0; i < n; i++) {
		int arr_item = stoi(arr_temp[i]);

		arr[i] = arr_item;
	}

	plusMinus(arr);

	return 0;
}