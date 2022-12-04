#include <bits/stdc++.h>
#include "input.h"

using namespace std;

int isPalindrome(string s, int beg, int end) {
    for (int i = 0; i+i <= end; i++) {
        if (s[i] != s[end-i]) return i;
    }
    return -1;
}

int palindromeIndex(string s) {
    size_t n = s.size();
    int fail = isPalindrome(s, 0, n-1);
    if (fail == -1) return -1;
    string s_c = s;
    s_c.erase(fail, 1);
    int fail_0 = isPalindrome(s_c, 0, n-2);
    if (fail_0 == -1) return fail;
    s_c = s;
    s_c.erase(n-1-fail, 1);
    fail_0 = isPalindrome(s_c, 0, n-2);
    if (fail_0 == -1) return n-1-fail;
    return -1;
}

int main() {
    string q_temp;
    getline(cin, q_temp);

    int q = stoi(ltrim(rtrim(q_temp)));

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string s;
        getline(cin, s);

        int result = palindromeIndex(s);
        cout << result << endl;
    }

    return 0;
}