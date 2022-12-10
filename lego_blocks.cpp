#include <bits/stdc++.h>
#include "input.h"

using namespace std;

vector<int> tetranacci(int m, int mod) {
    vector<int> tetra(m+1);
    tetra[0] = 1;
    tetra[1] = 1;
    tetra[2] = 2;
    tetra[3] = 4;
    for (int i = 4; i <= m; i++)
        tetra[i] = (tetra[i-4] + tetra[i-3] + tetra[i-2] + tetra[i-1]) % mod;
    return tetra;
}

// TODO: check edge cases
int legoBlocks(int n, int m) {
    int mod = 1000000000 + 7;
    vector<int> tetra = tetranacci(m, mod);
    vector<int> good(m+1), bad(m+1);

    good[1] = 1;

    for (int i = 2; i <= m; i++) {
        good[i] = int(pow(tetra[i], n)) % mod;
        for (int j = 1; j < i; j++) bad[i] += ((good[j] - bad[j]) * good[i-j]) % mod;
    }

    return (good[m] - bad[m]) % mod;
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

        int result = legoBlocks(n, m);

        cout << result << endl;
    }

    return 0;
}