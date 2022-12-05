#include <bits/stdc++.h>
#include "input.h"

using namespace std;

string gridChallenge(vector<string> grid) {
    // TODO: find failing test
    size_t n = grid.size();
    if (n == 1) return "YES";
    string s = grid[0];
    sort(s.begin(), s.end());
    for (size_t i = 1; i < n; i++) {
        string si =  grid[i];
        sort(si.begin(), si.end());
        if (s > si) return "NO";
        s = si;
    }
    return "YES";
}

int main() {
    string t_temp;
    getline(cin, t_temp);

    int t = stoi(ltrim(rtrim(t_temp)));

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string n_temp;
        getline(cin, n_temp);

        int n = stoi(ltrim(rtrim(n_temp)));

        vector<string> grid(n);

        for (int i = 0; i < n; i++) {
            string grid_item;
            getline(cin, grid_item);

            grid[i] = grid_item;
        }

        string result = gridChallenge(grid);

        cout << result << endl;
    }

    return 0;
}