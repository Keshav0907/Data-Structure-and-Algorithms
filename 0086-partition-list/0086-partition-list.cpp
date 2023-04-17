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
    ListNode* partition(ListNode* head, int x) {
        
        ListNode* dummy1 = new ListNode(-1);
        ListNode* dummy2 = new ListNode(0);
        ListNode* ptr1 = dummy1;
        ListNode* ptr2 = dummy2;
        
        ListNode* temp = head;
        
        while(temp!=NULL){
            
            if(temp->val < x) {
                dummy1->next = temp;
                dummy1 = dummy1->next;
            } else {
                dummy2->next = temp;
                dummy2 = dummy2->next;
            }
            temp = temp->next;
        }
        dummy2->next = NULL;
        dummy1->next = ptr2->next;
        return ptr1->next;
        
    }
};