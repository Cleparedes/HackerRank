#include <bits/stdc++.h>
#include "input.h"

using namespace std;

bool possibleTour(vector<int> diff, int start, int n) {
    long tank = 0;
    for (int i = start; i+start < n+start; i++) {
        int i_mod = i % n;
        tank += diff[i_mod];
        if (tank < 0) return false;
    }
    return true;
}

int truckTour(vector<vector<int>> petrolpumps) {
    size_t n = petrolpumps.size();
    vector<int> diff(n);
    for (int i = 0; i < n; i++) {
        diff[i] += (petrolpumps[i][0] - petrolpumps[i][1]);
    }
    for (int i = 0; i < n; i++) {
        if (possibleTour(diff, i, n)) return i;
    }
    return -1;
}

int main() {
    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    vector<vector<int>> petrolpumps(n);

        for (int i = 0; i < n; i++) {
            petrolpumps[i].resize(n);

            string petrolpumps_row_temp_temp;
            getline(cin, petrolpumps_row_temp_temp);

            vector<string> petrolpumps_row_temp = split(rtrim(petrolpumps_row_temp_temp));

            for (int j = 0; j < 2; j++) {
                int petrolpumps_row_item = stoi(petrolpumps_row_temp[j]);
                
                petrolpumps[i][j] = petrolpumps_row_item;
            }
        }
    
    int result = truckTour(petrolpumps);
    
    cout << result << endl;

    return 0;
}