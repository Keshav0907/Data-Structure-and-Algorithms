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
    
    ListNode* KthFront(ListNode* head,int k) {
        ListNode* temp = head;
        k = k - 1;
        while(k--) {
            temp=temp->next;
        }
      return temp;  
    }
    
    ListNode* KthEnd(ListNode* head,int k) {
        
        ListNode * temp1 = head;
        ListNode* temp2 = head;
        
        while(k--){
            temp1 = temp1->next;
        }
        
        while(temp1) {
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        
        return temp2;
        
    }
    
    ListNode* swapNodes(ListNode* head, int k) {
        
        ListNode * kFromBeg = KthFront(head,k);
        ListNode * kFromEnd = KthEnd(head,k);
        
        swap(kFromBeg->val,kFromEnd->val);
        return head;
        
    }
};