// https://leetcode.com/problems/middle-of-the-linked-list/description/

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
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        int size = 0;

        while(fast) {
            fast = fast->next;
            size++;
            if(size % 2 == 0) {
                slow = slow->next;
            }
        }

        return slow;
    }
};