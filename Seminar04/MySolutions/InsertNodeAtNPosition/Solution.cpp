// https://www.hackerrank.com/contests/sda-hw-3-2025/challenges/insert-a-node-at-a-specific-position-in-a-linked-list/submissions/code/1399785283

/*
 * Complete the 'insertNodeAtPosition' function below.
 *
 * The function is expected to return an INTEGER_SINGLY_LINKED_LIST.
 * The function accepts following parameters:
 *  1. INTEGER_SINGLY_LINKED_LIST llist
 *  2. INTEGER data
 *  3. INTEGER position
 */

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */

SinglyLinkedListNode* insertNodeAtPosition(SinglyLinkedListNode* llist, int data, int position) {
    SinglyLinkedListNode* curr = llist;

    for (int i = 0; i < position - 1; i++) {
        if (curr) curr = curr->next;
        else return llist;
    }
    
    SinglyLinkedListNode* newNode = new SinglyLinkedListNode(data);
    newNode->next = curr->next;
    curr->next = newNode;
    
    if(position == 0) llist = newNode;
    return llist;
}