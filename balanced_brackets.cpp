#include <bits/stdc++.h>
#include "input.h"

using namespace std;

string isBalanced(string s) {
    stack<char> stack;
    for (size_t i = 0; i < s.size(); i++) {
        switch (s[i]) {
            case ')':
                if (!stack.empty() && stack.top() == '(') stack.pop();
                else return "NO";
                break;
            case '}':
                if (!stack.empty() && stack.top() == '{') stack.pop();
                else return "NO";
                break;
            case ']':
                if (!stack.empty() && stack.top() == '[') stack.pop();
                else return "NO";
                break;
            default:
                stack.push(s[i]);
        }
    }
    return "YES";
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