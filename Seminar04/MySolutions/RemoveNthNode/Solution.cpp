// https://www.hackerrank.com/contests/sda-hw-3-2025/challenges/delete-a-node-from-a-linked-list/problem

/*
 * Complete the 'deleteNode' function below.
 *
 * The function is expected to return an INTEGER_SINGLY_LINKED_LIST.
 * The function accepts following parameters:
 *  1. INTEGER_SINGLY_LINKED_LIST llist
 *  2. INTEGER position
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

SinglyLinkedListNode* deleteNode(SinglyLinkedListNode* llist, int position) {
    if (!llist) return nullptr;

    if (position == 0) {
        SinglyLinkedListNode* temp = llist;
        llist = llist->next;
        delete temp;
        return llist;
    }

    SinglyLinkedListNode* curr = llist;
    for (int i = 0; i < position - 1 && curr; i++) {
        curr = curr->next;
    }

    if (!curr || !curr->next) return llist;

    SinglyLinkedListNode* temp = curr->next;
    curr->next = temp->next;
    delete temp;

    return llist;
}
