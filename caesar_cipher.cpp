#include <bits/stdc++.h>
#include "input.h"

using namespace std;

string caesarCipher(string s, int k) {
    k %= 26;
    for (size_t i = 0; i < s.size(); i++) {
        unsigned char shift = s[i];
        if (shift >= 'a' && shift <= 'z') {
            shift += k;
            if (shift > 'z') shift += ('a' - 1 - 'z');
            s[i] =  shift;
            continue;
        }
        if (shift >= 'A' && shift <= 'Z') {
            shift += k;
            if (shift > 'Z') shift += ('A' - 1 - 'Z');
            s[i] = shift;
            continue;
        }
    }
    return s;
}

int main() {
    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    string s;
    getline(cin, s);

    string k_temp;
    getline(cin, k_temp);

    int k = stoi(ltrim(rtrim(k_temp)));

    string result = caesarCipher(s, k);

    cout << result << endl;

    return 0;
}