#include <bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    Node* next;
    Node* prev;
    Node(int v) : val(v), next(nullptr), prev(nullptr) {}
};

struct Cheats {
    Node* head = nullptr;
    Node* tail = nullptr;
    Node* mid  = nullptr;
    int size = 0;

    void add(int x) {
        Node* n = new Node(x);
        if (!head) {
            head = tail = mid = n;
            size = 1;
            return;
        }
        tail->next = n;
        n->prev = tail;
        tail = n;
        size++;
        if (size % 2 == 0) mid = mid->next;
    }

    void gun() {
        if (!tail) return;
        Node* old = tail;
        tail = tail->prev;
        if (tail) tail->next = nullptr;
        else head = nullptr;
        delete old;
        size--;
        if (size == 0) mid = nullptr;
        else if (size % 2 == 1) mid = mid->prev;
    }

    void milen() {
        if (size < 2) return;

        if (mid == head) return;

        Node* leftTail = mid->prev;
        Node* rightHead = mid;

        leftTail->next = nullptr;
        rightHead->prev = nullptr;

        tail->next = head;
        head->prev = tail;

        mid = (size % 2 == 0) ? head : tail;

        head = rightHead;
        tail = leftTail;
    }

    void print() {
        cout << size << "\n";
        for (Node* cur = head; cur; cur = cur->next)
            cout << cur->val << " ";
    }

    ~Cheats() {
        Node* cur = head;
        while (cur) {
            Node* nxt = cur->next;
            delete cur;
            cur = nxt;
        }
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    if (!(cin >> N)) return 0;
    Cheats c;
    while (N--) {
        string cmd;
        cin >> cmd;
        if (cmd == "add") {
            int x; cin >> x;
            c.add(x);
        } else if (cmd == "gun") {
            c.gun();
        } else if (cmd == "milen") {
            c.milen();
        }
    }
    c.print();
    return 0;
}
