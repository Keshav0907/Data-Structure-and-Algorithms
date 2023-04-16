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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
       
        ListNode* prev = NULL;
        ListNode* curr = head;
        
        while(left > 1) {
            prev = curr;
            curr = curr->next;
            left--;
            right--;
        }
       
        ListNode* connect = prev;
        ListNode* tail = curr;
        
        ListNode* next;
        
        while(right > 0) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            right--;
        }
            
        if(connect!=NULL) {
            connect->next = prev;
        } else {
            head = prev;
        }
        
        tail->next = curr;
        
        return head;
    }
};