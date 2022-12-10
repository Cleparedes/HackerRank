#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
#include <tuple>

using namespace std;

class TextEditor {
    public:
        string s;
        stack<tuple<int, string>> ops;

        TextEditor() {
            stack<tuple<int, string>> ops;
            this->s = "";
            this->ops = ops;
        }

        void append(string w) {
            int k = w.size();
            this->ops.push(make_tuple(1, to_string(k)));
            this->s.append(w);
        }

        void _delete(int k) {
            string s = this->s;
            size_t n = s.size();
            this->ops.push(make_tuple(2, s.substr(n-k, k)));
            this->s = s.substr(0, n-k);
        }

        void print(int k) {
            cout << this->s[k-1] << endl;
        }

        void undo() {
            if (!this->ops.empty()) {
                tuple<int, string> top = this->ops.top();
                this->ops.pop();
                size_t n = top.size();
                if (get<0>(top) == 1) {
                    int k = stoi(get<1>(top));
                    this->_delete(k);
                }
                if (get<0>(top) == 2) this->append(get<1>(top));
                this->ops.pop();
            }   
        }
};

int main() {
    int q;
    cin >> q;

    TextEditor* text_editor = new TextEditor();

    int op, k;
    string w;
    for (int i = 0; i < q; i++) {
        cin >> op;
        switch (op) {
            case 1:
                cin >> w;
                text_editor->append(w);
                break;
            case 2:
                cin >> k;
                text_editor->_delete(k);
                break;
            case 3:
                cin >> k;
                text_editor->print(k);
                break;
            case 4:
                text_editor->undo();
        }
    }

    return 0;
}