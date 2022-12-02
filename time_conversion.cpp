#include <bits/stdc++.h>

using namespace std;

string timeConversion(string s) {
    char c = s[8];
    int h = stoi(s.substr(0, 2));
    string r = s.substr(0, 8);
    if (h == 12) h = 0;
    if (c == 'P') h += 12;
    r[0] = to_string(h/10)[0];
    r[1] = to_string(h%10)[0];
    return r;
}

int main() {
    string s;
    getline(cin, s);

    string result = timeConversion(s);

    cout << result << endl;

    return 0;
}