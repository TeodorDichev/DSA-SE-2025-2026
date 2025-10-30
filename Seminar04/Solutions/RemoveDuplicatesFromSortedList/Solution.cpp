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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head) return head;

        ListNode* curr = head;
        while(curr) {
            auto iter = curr;
            while(iter && iter->val == curr->val) {
                curr->next = iter->next;
                delete iter;
                iter = curr->next;
            }
            curr = iter;
        }
        
        return head;
    }
};