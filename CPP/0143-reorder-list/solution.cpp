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
    void reorderList(ListNode* head) {
        ListNode *slow = head, *fast=head;
        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode *secondH = slow->next;
        slow->next=NULL;

        //reverse second half
        ListNode *prev;
        prev=NULL;
        while(secondH){
            ListNode *temp = secondH->next;
            secondH->next = prev;
            prev = secondH;
            secondH = temp;
        }

        //merge first half and second half
        ListNode *first = head, *second = prev;
        while(second){
            ListNode *temp1=first->next, *temp2=second->next;
            first->next = second;
            second->next = temp1;
            first = temp1;
            second = temp2;
        }
    }
};
