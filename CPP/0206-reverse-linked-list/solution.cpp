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
    ListNode* reverseList(ListNode* head) {
        return helper(head);
    }
    ListNode* helper(ListNode* cur){
        if(!cur || !cur->next)   return cur;

        ListNode *head = helper(cur->next);
        ListNode *nextN = cur->next;
        nextN->next = cur; 
        cur->next=NULL;     //or else it will form loop between first and second node
        return head;
    }
};
