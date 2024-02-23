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
    int pairSum(ListNode* head) {

        ListNode *slow=head,*fast=head;
        while(fast && fast->next){
            fast=fast->next->next;
            slow=slow->next;
        }
        //Now slow points to middle of LL
        //Let's reverse the second half
        ListNode *prev=NULL,*nextNode;
        while(slow){
            nextNode=slow->next;
            slow->next=prev;
            prev=slow;
            slow=nextNode;
        }
        //start adding values from start and end
        //start points start of LL, prev points to end
        ListNode *start=head;
        int maxSum=0;
        while(prev){
            maxSum = max(maxSum,start->val+prev->val);
            prev=prev->next;
            start=start->next;
        }
        return maxSum;
    }
};
