#include <bits/stdc++.h>
#include "input.h"

using namespace std;

int towerBreakers(int n, int m) {
    if (m == 1) return 2;
    return 2 - (n % 2);
}

int main () {
    string t_temp;
    getline(cin, t_temp);

    int t = stoi(ltrim(rtrim(t_temp)));

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string first_multiple_input_temp;
        getline(cin, first_multiple_input_temp);

        vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

        int n = stoi(first_multiple_input[0]);

        int m = stoi(first_multiple_input[1]);

        int result = towerBreakers(n, m);

        cout << result << endl;
    }

    return 0;
}