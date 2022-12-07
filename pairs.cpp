#include <bits/stdc++.h>

using namespace std;

int pairs(int k, vector<int> arr) {
    size_t n = arr.size();
    int pairs = 0;
    sort(arr.begin(), arr.end());
    for (size_t i = 0; i < n; i++) {
        for (size_t j = i; j < n; j++) {
            if (arr[j] - arr[i] == k) {
                pairs++;
                continue;
            }
            if (arr[j] - arr[i] > k) break;
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