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
        if(!head || !head->next)    return head;

        ListNode* prevN = NULL;
        ListNode* curN = head;
        while(curN){
            ListNode* nextN = curN->next;
            curN->next = prevN;

            prevN=curN;
            curN=nextN;
        }
        head = prevN;
        return head;
    }
};
