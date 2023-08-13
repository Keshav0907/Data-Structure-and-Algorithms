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
            int sum = 0;
            int a = l1==NULL ? 0 : l1->val;
            int b = l2==NULL ? 0 : l2->val;
            sum = sum + a + b + carry;
            ListNode* temp1 = new ListNode(sum%10);
            carry = sum/10;
            temp->next = temp1;
            temp = temp->next;
            if(l1) l1 = l1->next;
            if(l2) l2 = l2->next;   
        }
   
        return dummy->next;
    }
};