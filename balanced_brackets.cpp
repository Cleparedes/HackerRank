#include <bits/stdc++.h>
#include "input.h"

using namespace std;

string isBalanced(string s) {
    stack<char> stack;
    for (size_t i = 0; i < s.size(); i++) {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[') stack.push(s[i]);
        else {
            if (stack.empty()) return "NO";
            char top = stack.top();
            stack.pop();
            if (top == '(' && s[i] == ')') continue;
            if (top == '{' && s[i] == '}') continue;
            if (top == '[' && s[i] == ']') continue;
            return "NO";
        }
    }
    if (stack.empty()) return "YES";
    return "NO";
}

int main() {
    string t_temp;
    getline(cin, t_temp);

    int t = stoi(ltrim(rtrim(t_temp)));

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string s;
        getline(cin, s);

        string result = isBalanced(s);

        cout << result << endl;
    }
}