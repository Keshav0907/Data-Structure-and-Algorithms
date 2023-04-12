/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// class Solution {
// public:
//     ListNode *detectCycle(ListNode *head) {
     
//      ListNode* fast = head->next;
//      ListNode* slow = head;
//      ListNode* dummy = head;
        
//      while(fast->next && fast->next->next) {
//          slow = slow->next;
//          fast = fast->next->next;
//          if(slow==fast) {
             
//              while(slow!=dummy) {
//                  slow = slow->next;
//                  dummy = dummy->next;
//              }
//              return dummy;
//          }
     
         
//      }
        
//      return NULL;
        
//     }
// };

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (head == NULL || head->next == NULL)
            return NULL;
    
        ListNode *slow  = head;
        ListNode *fast  = head;
        ListNode *entry = head;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {                      // there is a cycle
                while(slow != entry) {               // found the entry location
                    slow  = slow->next;
                    entry = entry->next;
                }
                return entry;
            }
        }
        return NULL;      
    }
};