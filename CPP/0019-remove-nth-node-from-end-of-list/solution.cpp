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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head || !head->next)   return NULL;
        ListNode *temp=head;
        ListNode *before=head;
        //find length of LL
        int length=0;
        while(temp){
            temp=temp->next;
            length++;
        }
        
        //if head is to be deleted
        if(n==length)   return head->next;

        //k will be the index of node just before the node to be deleted
        int k=length-n-1;
        while(k-- && before->next)
            before=before->next;
        before->next=before->next->next;
        return head;
    }    
};
