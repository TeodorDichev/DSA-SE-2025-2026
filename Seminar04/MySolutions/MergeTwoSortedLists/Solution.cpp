// https://leetcode.com/problems/merge-two-sorted-lists/submissions/1816043056/?fbclid=IwY2xjawNu9TtleHRuA2FlbQIxMABicmlkETFJV2s5cG83NDU1SU9rMWNqAR5jcu-QXEA9OsSzo78Am6aICpAGqr3jjIywQENlCnW_ii73r2IaOeeXdlQEuA_aem_2wcpbzze83EgmquDUPAL5g

#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1 == NULL)
            return list2;
		
        if(list2 == NULL)
            return list1;
        
        ListNode * ptr = list1;
        if(list1 -> val > list2 -> val) {
            ptr = list2;
            list2 = list2 -> next;
        }
        else {
            list1 = list1 -> next;
        }
        ListNode *curr = ptr;
        
        while(list1 &&  list2) {
            if(list1 -> val < list2 -> val) {
                curr->next = list1;
                list1 = list1 -> next;
            }
            else {
                curr->next = list2;
                list2 = list2 -> next;
            }
            curr = curr -> next;
        }
		
        if(!list1)
            curr -> next = list2;
        else
            curr -> next = list1;
            
        return ptr;
    }
};

//https://www.hackerrank.com/contests/sda-hw-3-2025/challenges/merge-two-sorted-linked-lists/submissions/code/1399786047
// second solution
// Complete the mergeLists function below.

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */
SinglyLinkedListNode* mergeLists(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) {
    SinglyLinkedListNode* newHead = nullptr;
    
    if(head1 && head2 && head1->data < head2->data) {
        newHead = new SinglyLinkedListNode(head1->data);
        head1 = head1->next;
    }
    else if(head1 && head2 && head1->data >= head2->data) {
        newHead = new SinglyLinkedListNode(head2->data);
        head2 = head2->next;
    }
    else {
        return newHead;
    }
    
    SinglyLinkedListNode* nextNode = nullptr, *prevNode = newHead;
    while(head1 && head2) {
        if(head1->data > head2->data) {
            nextNode = new SinglyLinkedListNode(head2->data);
            prevNode->next = nextNode;
            prevNode = nextNode;
            head2 = head2->next;
        } else {
            nextNode = new SinglyLinkedListNode(head1->data);
            prevNode->next = nextNode;
            prevNode = nextNode;
            head1 = head1->next;
        }
    }
    
    while(head1) {
        nextNode = new SinglyLinkedListNode(head1->data);
        prevNode->next = nextNode;
        prevNode = nextNode;
        head1 = head1->next;
    }
    
    while(head2) {
        nextNode = new SinglyLinkedListNode(head2->data);
        prevNode->next = nextNode;
        prevNode = nextNode;
        head2 = head2->next;
    }
    
    return newHead;

}