// you get a linked list where only 1 element is 0, 
// send all negative node before 0 and all positive after

#include <bits/stdc++.h>
using namespace std;

struct Node {
    Node* next;
    int val;

    Node() {}
    Node(int val = 0, Node* next = nullptr) : val(val), next(next) { }
};

void add(Node*& head, Node*& tail, Node*& curr) {
    if (head == nullptr)
	{
		head = tail = curr;
	}
	else
	{
		tail->next = curr;
		tail = curr;
	}
}

void printList(Node* iter)
{
	while (iter)
	{
		std::cout << iter->val;
		if(iter->next)
		   std::cout << " -> ";
		
        iter = iter->next;
	}
    cout << "\n";
}

void freeList(Node* iter)
{
	while (iter)
	{
		Node* toDelete = iter;
		iter = iter->next;
		delete toDelete;
	}
}

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    // 3 -> -4 -> 5 -> -6 -> 0 -> -1 -> -2 -> 7
    // expected -4 -> -6 -> -1 -> -2 -> 0 -> 3 -> 5 -> 7 -> 2
    Node* list = new Node{ 3, new Node{-4, new Node{5, new Node{-6, new Node{0, new Node{-1, new Node{-2, new Node{7, new Node{2}}}}}}}}};
    Node* negHead = nullptr;
    Node* negTail = nullptr;
    Node* posHead = nullptr;
    Node* posTail = nullptr;
    Node* zeroNode = nullptr;

    Node* curr = list;
    while (curr) {
        Node* next = curr->next;
        curr->next = nullptr;  // detach each node

        if (curr->val < 0) add(negHead, negTail, curr);
        else if (curr->val > 0) add(posHead, posTail, curr);
        else zeroNode = curr;  // store the 0 node

        curr = next;
    }

    // connect in order: negatives -> zero -> positives
    Node* head = nullptr;
    if (negTail) negTail->next = zeroNode;
    if (zeroNode) zeroNode->next = posHead;

    if (negHead) head = negHead;
    else if (zeroNode) head = zeroNode;
    else head = posHead;
 
	negHead  = negHead ? negHead : posHead;

    printList(negHead);
    freeList(negHead);
}