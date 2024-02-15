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
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || k == 0) return head;
        int len = 1;
        ListNode *right = head;
        while (right->next) { 
            len++;
            right = right->next;
        }
        k = k%len;
        if (k == 0) return head;
        
        ListNode *left = head;
        for (int i = 0; i < len - k - 1; i++) { 
            left = left->next;
        }

        ListNode *newH = left->next;
        left->next = NULL;
        right->next=head;

        return newH;
    }
};
