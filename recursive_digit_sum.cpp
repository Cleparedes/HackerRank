#include <bits/stdc++.h>
#include "input.h"

using namespace std;

int superDigit(string n, int k) {
    if (n.size() == 1) return stoi(n);
    vector<long> d(10);
    for (size_t i = 0; i < n.size(); i++) d[(n[i] - '0')]++;
    long sum = 0;
    for (int i = 1; i <= 9; i++) sum += d[i] * k * i;
    return superDigit(to_string(sum), 1);
}

int main() {
    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    string n = first_multiple_input[0];

    int k = stoi(first_multiple_input[1]);

    int result = superDigit(n, k);

    cout << result << endl;

    return 0;
}