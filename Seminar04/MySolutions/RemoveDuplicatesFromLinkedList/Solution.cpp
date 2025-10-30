//https://leetcode.com/problems/remove-duplicates-from-sorted-list/description/

#include <bits/stdc++.h>

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

struct ListNode
{
    ListNode* next;
    int val;
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* curr = head;
        ListNode* next;

        while(curr && curr->next) {
            next = curr->next;
            if(next->val == curr->val) {
                curr->next = next->next;
                // delete next; // add if you are on paper
            }
            else {
                curr = curr->next;
            }
        }

        return head;
    }
};