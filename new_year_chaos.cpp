#include <bits/stdc++.h>
#include "input.h"

using namespace std;

void minimumBribes(vector<int> q) {
    long bribes = 0;
    for (int i = q.size()-1; i >= 0; i--) {
        if (q[i] == i+1) continue;
        int temp = q[i];
        if (q[i-1] == i+1) {
            q[i] = q[i-1];
            q[i-1] = temp;
            bribes++;
        } else {
            if (q[i-2] == i+1) {
                q[i] = q[i-2];
                q[i-2] = q[i-1];
                q[i-1] = temp;
                bribes += 2;
            } else {
                cout << "Too chaotic" << endl;
                return;
            }
        }
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