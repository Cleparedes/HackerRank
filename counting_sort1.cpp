#include <bits/stdc++.h>
#include "input.h"

using namespace std;

vector<int> countingSort(vector<int> arr) {
    vector<int> f(100);
    for (size_t i = 0; i < arr.size(); i++) f[arr[i]]++;
    return f;
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

    vector<int> result = countingSort(arr);

    for (size_t i = 0; i < result.size(); i++) {
        cout << result[i];

        if(i != result.size() - 1) cout << " ";
    }

    cout << endl;

    return 0;
}