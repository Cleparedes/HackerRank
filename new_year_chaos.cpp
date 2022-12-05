#include <bits/stdc++.h>
#include "input.h"

using namespace std;

void minimumBribes(vector<int> q) {
    long bribes = 0;
    for (int i = 0; i < q.size(); i++) {
        if (q[i] > i+3) {
            cout << "Too chaotic" << endl;
            return;
        }
        // TODO: check bribe count
        if (q[i] > i+1) bribes += (q[i] - i-1);
    }
    cout << bribes << endl;
}

int main() {
    string t_temp;
    getline(cin, t_temp);

    int t = stoi(ltrim(rtrim(t_temp)));

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string n_temp;
        getline(cin, n_temp);

        int n = stoi(ltrim(rtrim(n_temp)));

        string q_temp_temp;
        getline(cin, q_temp_temp);

        vector<string> q_temp = split(rtrim(q_temp_temp));

        vector <int> q(n);

        for (int i = 0; i < n; i++) {
            int q_item = stoi(q_temp[i]);

            q[i] = q_item;
        }

        minimumBribes(q);
    }

    return 0;
}