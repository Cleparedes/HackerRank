#include <bits/stdc++.h>
#include "input.h"

using namespace std;

int flippingMatrix(vector<vector<int>> matrix) {
    size_t n2 = matrix.size();
    size_t n = n2/2;
    long sum = 0;
    for (size_t i = 0; i < n; i++) {
        for (size_t j = 0; j < n; j++) {
            int max = matrix[i][j];
            if (max < matrix[i][n2-1-j]) max = matrix[i][n2-1-j];
            if (max < matrix[n2-1-i][j]) max = matrix[n2-1-i][j];
            if (max < matrix[n2-1-i][n2-1-j]) max = matrix[n2-1-i][n2-1-j];
            sum += max;
        }
    }
    return sum;
}

int main() {
    string q_temp;
    getline(cin, q_temp);

    int q = stoi(ltrim(rtrim(q_temp)));

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string n_temp;
        getline(cin, n_temp);

        int n = stoi(ltrim(rtrim(n_temp)));

        vector<vector<int>> matrix(2 * n);

        for (int i = 0; i < 2 * n; i++) {
            matrix[i].resize(2 * n);

            string matrix_row_temp_temp;
            getline(cin, matrix_row_temp_temp);

            vector<string> matrix_row_temp = split(rtrim(matrix_row_temp_temp));

            for (int j = 0; j < 2 * n; j++) {
                int matrix_row_item = stoi(matrix_row_temp[j]);

                matrix[i][j] = matrix_row_item;
            }
        }

        int result = flippingMatrix(matrix);

        cout << result << endl;
    }

    return 0;
}