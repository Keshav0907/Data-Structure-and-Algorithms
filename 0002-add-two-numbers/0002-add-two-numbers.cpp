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
        
        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy;
        int carry = 0;
        while(l1!=NULL || l2!=NULL || carry) {
            int l1_val = (l1==NULL) ? 0 : l1->val;
            int l2_val = (l2==NULL) ? 0 : l2->val;
            int sum = l1_val + l2_val + carry;
            carry = sum/10;
            int lastDigit = sum%10;
            ListNode* n = new ListNode(lastDigit);
            temp->next = n;
            temp = temp->next;
            if(l1) l1 = l1->next;
            if(l2) l2 = l2->next;
        } 
        
        return dummy->next;
    }
};