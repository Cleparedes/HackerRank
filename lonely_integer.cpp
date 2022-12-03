#include <bits/stdc++.h>
#include "input.h"

using namespace std;

int lonelyinteger(vector<int> arr) {
    unordered_map<int, int> umap;
    for (size_t i = 0; i < arr.size(); i++) umap[arr[i]]++;
    for (auto e : umap) {
        if (e.second == 1) return e.first;
    }
    return -1;
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

    int result = lonelyinteger(arr);

	cout << result << endl;

	return 0;
}