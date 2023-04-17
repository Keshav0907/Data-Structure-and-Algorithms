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
    
    ListNode* getMid(ListNode* head) {
        
        ListNode* slow = head;
        ListNode* fast = head->next;
        
        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        return slow;
        
        
    }
    
    ListNode* merge(ListNode* a,ListNode* b) {
        
        if(a==NULL) {
            return b;
        } else if(b==NULL) {
            return a;
        }
        
        ListNode* temp;
        
        if(a->val <= b->val) {
            temp = a;
            temp->next = merge(a->next,b);
        } else {
            temp = b;
            temp->next = merge(a,b->next);
        }
        
         return temp;
        
    }
    
//       ListNode* merge(ListNode* a,ListNode* b) {
        
//         ListNode* dummy = new ListNode(-1);
//         ListNode* curr = dummy;
//         while(a && b) {
            
//             if(a->val <= b->val) {
//                 dummy->next = a;
//                 a = a->next;
//             } else {
//                 dummy->next = b;
//                 b = b->next;
//             }
            
//             dummy = dummy->next;
            
//         }
        
//         if(a) dummy->next = a;
//         if(b) dummy->next = b;
        
//         return curr->next;
//       }
    
    ListNode* sortList(ListNode* head) {
        
        if(!head || head->next==NULL) {
            return head;
        }
        
        ListNode* mid = getMid(head);
        ListNode* left  = head;
        ListNode* right = mid->next;
        mid->next = NULL;
        left = sortList(left);
        right = sortList(right);
        return merge(left,right);
          
    }
};


