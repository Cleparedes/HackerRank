#include <bits/stdc++.h>
#include "input.h"

using namespace std;

void miniMaxSum(vector<int> arr) {
    long min = *min_element(arr.begin(), arr.end());
    long max = *max_element(arr.begin(), arr.end());
    long sum = accumulate(arr.begin(), arr.end(), 0);
    cout << sum - max << " " << sum - min << endl;
}

int main() {
    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split(rtrim(arr_temp_temp));

    vector<int> arr(5);

    for (int i = 0; i < 5; i++) {
        int arr_item = stoi(arr_temp[i]);

        arr[i] = arr_item;
    }

    miniMaxSum(arr);

    return 0;
}