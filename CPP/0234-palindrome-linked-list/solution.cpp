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
    ListNode* reverseLL(ListNode* head) {
        if(!head || !head->next)    return head;
        ListNode *prev = NULL, *next = NULL;
        while(head){
            next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        ListNode *slow=head, *fast=head;
        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }

        //reverse second half
        ListNode* sHead = reverseLL(slow);

        //compare first half and second half
        ListNode *fHead = head;
        while(sHead){
            if(fHead->val != sHead->val)   return false;
            fHead=fHead->next;
            sHead=sHead->next;
        }
        return true;
    }
};
