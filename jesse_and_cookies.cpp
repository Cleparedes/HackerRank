#include <bits/stdc++.h>
#include "input.h"

using namespace std;

int cookies(int k, vector<int> A) {
    priority_queue<int, vector<int>, greater<>> queue(A.begin(), A.end());
    int c = 0;
    while (queue.top() < k && queue.size() > 1) {
        int min = queue.top();
        queue.pop();
        int sec = queue.top();
        queue.pop();
        queue.push(min + 2 * sec);
        c++;
    }
    if (queue.top() >= k) return c;
    return -1;
}

int main() {
    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n = stoi(first_multiple_input[0]);

    int k = stoi(first_multiple_input[1]);

    string A_temp_temp;
    getline(cin, A_temp_temp);

    vector<string> A_temp = split(rtrim(A_temp_temp));

    vector<int> A(n);

    for (int i = 0; i < n; i++) {
        int A_item = stoi(A_temp[i]);

        A[i] = A_item;
    }

    int result = cookies(k, A);

    cout << result << endl;

    return 0;
}