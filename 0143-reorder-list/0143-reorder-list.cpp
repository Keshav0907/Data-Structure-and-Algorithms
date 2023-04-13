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
    
 
     ListNode* reverse(ListNode* head) {
        
        ListNode* curr = head;
        ListNode* prev = NULL;
        ListNode* next = NULL;
        
        while(curr!=NULL) {
            
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            
        }
        
        return prev;
    }
    void reorderList(ListNode* head) {
        
        ListNode* fast = head->next;
        ListNode* slow = head;
        
        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        ListNode* secondptr = reverse(slow->next);
        slow->next = NULL;
        ListNode* firstptr = head;

        
        while(secondptr) {
            
            ListNode* temp1 = firstptr->next;
            ListNode* temp2 = secondptr->next;
            
            firstptr->next = secondptr;
            secondptr->next = temp1;
            firstptr = temp1;
            secondptr = temp2;
            
        }
      
    }
};