#include <bits/stdc++.h>

using namespace std;

int pairs(int k, vector<int> arr) {
    size_t n = arr.size();
    int pairs = 0;
    for (size_t i = 0; i < n-1; i++) {
        for (size_t j = i; j < n; j++) {
            if (arr[i] - arr[j] == k || arr[j] - arr[i] == k) pairs++; 
        }
    }
    return pairs;
}

int main () {
    int n, k;
    cin >> n >> k;

    vector<int> arr(n);

    for (int i = 0; i < n; i++) cin >> arr[i];

    int result = pairs(k, arr);
    cout << result << endl;

    return 0;
}