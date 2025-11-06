// https://www.hackerrank.com/contests/sda-hw-3-2025/challenges/cache-8/problem

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int key, value;
    Node* next = nullptr;
    Node* prev = nullptr;

    Node(int key, int val) : key(key), value(val) {}
};

struct List
{
    Node* cache[10001]{nullptr};
    Node* head;
    Node* tail;
    int size = 0;
    int max_size = 0;

    List(int max_size) : max_size(max_size) {}

    void pop_back() {
        if(!tail || !head || tail == head) {
            tail = head = nullptr;
            size = 0;
            return;
        }

        // at least 2 elements
        if(tail->prev) tail->prev->next = nullptr;
        delete tail;
        size--;
    }

    void move_to_front(Node* node) {
        head->prev = node;
        Node* prev = node->prev;
        Node* next = node->next; // next could be nullptr if node is tail
        prev->next = next;

        if(next) next->prev = prev;

        node->next = head;
        head = node;
    }

    void put(int key, int val) {
        Node* curr = cache[key];
        if(curr && head != curr) {
            move_to_front(curr);
            return;
        }

        if(size == max_size) 
            pop_back();

        size++;
        Node* newNode = new Node(key, val);
        cache[key] = newNode;

        if(head) {
            head->prev = newNode;
            newNode->next = head;
        }
            
        head = newNode;

        if(!tail)
            tail = head;
    }

    int get(int key) {
        Node* curr = cache[key];
        if(curr && head && head != curr) move_to_front(curr);

        return curr ? curr->value : -1;
    }   
};



int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N,Q,K;
    cin >> N >> Q >> K;
    List list(N);
    for(int i = 0, j = 0; i < Q; i++) {
        
        string command;
        cin >> command;
        if(j == K) {
            j = 0;
            list.pop_back();
        }

        if(command == "put") {
            int key, value;
            cin >> key >> value;
            list.put(key, value);
            j++;
        }
        else if(command == "get") {
            int key;
            cin >> key;
            cout << list.get(key) << "\n";
            j++;
        }
        else {
            continue;
        }
    }
    return 0;
}