#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

class Queue {
    public:
        stack<int> head;
        stack<int> tail;

        Queue() {
            stack<int> head, tail;
            this->head = head;
            this->tail = tail;
        }

        void enqueue(int x) {
            this->head.push(x);
        }

        void rebase() {
            size_t n = this->head.size();
            for (size_t i = 0; i < n; i++) {
                int top = this->head.top();
                this->head.pop();
                this->tail.push(top);
            }
        }

        void dequeue() {
            if (this->tail.empty()) this->rebase();
            this->tail.pop();
        }

        void print() {
            if (this->tail.empty()) this->rebase();
            cout << this->tail.top() << endl;
        }
};

int main() {
    int q;
    cin >> q;

    Queue* queue = new Queue();

    for (int i = 0; i < q; i++) {
        int t, x;
        cin >> t;
        switch (t) {
            case 1:
                cin >> x;
                queue->enqueue(x);
                break;
            case 2:
                queue->dequeue();
                break;
            case 3:
                queue->print();
        }
    }

    return 0;
}