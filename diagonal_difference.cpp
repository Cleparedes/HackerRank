#include <bits/stdc++.h>
#include "input.h"

using namespace std;

int diagonalDifference(vector<vector<int>> arr) {
    size_t n = arr.size();
    long l = 0, r = 0;
    for (size_t i = 0; i < n; i++) {
        l += arr[i][i];
        r += arr[i][n-1-i];
    }
    return abs(l -r);
}

int main() {
    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    vector<vector<int>> arr(n);

    for (int i = 0; i < n; i++) {
        arr[i].resize(n);

        string arr_row_temp_temp;
        getline(cin, arr_row_temp_temp);

        vector<string> arr_row_temp = split(rtrim(arr_row_temp_temp));

        for (int j = 0; j < n; j++) {
            int arr_row_item = stoi(arr_row_temp[j]);

            arr[i][j] = arr_row_item;
        }
    }

    int result = diagonalDifference(arr);

    cout << result << endl;

    return 0;
}