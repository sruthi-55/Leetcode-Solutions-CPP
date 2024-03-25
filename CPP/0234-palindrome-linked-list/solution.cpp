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
    bool isPalindrome(ListNode* head) {
        if(!head)   return true;

        stack<ListNode*> stack;
        ListNode *ptr = head;
        int size=0;
        while(ptr){
            stack.push(ptr);
            ptr=ptr->next;
            size++;
        }
        
        ListNode *ptr1=head;
        for(int i=0;i<size/2;i++){
            ListNode* ele=stack.top();
            stack.pop();
            if(ptr1->val!=ele->val){
                return false;
            }   
            ptr1=ptr1->next;
        }
        return true;
    }
};
