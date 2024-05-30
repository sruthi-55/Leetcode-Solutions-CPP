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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(!l1 && !l2)  return NULL;
        else if(!l1) return l2;
        else if(!l2)    return l1;

        stack<int> s1,s2;
        ListNode *t1=l1,*t2=l2;
        while(t1){
            s1.push(t1->val);
            t1=t1->next;
        }   
        while(t2){
            s2.push(t2->val);
            t2=t2->next;
        }   

        ListNode *res = new ListNode(0);
        while(!s1.empty() || !s2.empty()){
            int sum = res->val;
            if(!s1.empty()){
                sum += s1.top();  s1.pop();
            } 
            if(!s2.empty()){
                sum += s2.top();    s2.pop();
            }
            

            res->val = sum % 10;
            ListNode* head = new ListNode(sum/10);
            head->next = res;
            res = head;
        }
        return res->val ? res : res->next;
    }
};
