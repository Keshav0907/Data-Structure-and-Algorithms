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
    
       ListNode* getMid(ListNode* head) {
        
        ListNode* slow = head;
        ListNode* fast = head->next;
        
        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        return slow;
        
    }
    
//     int pairSum(ListNode* head) {
        
//         ListNode* dummy = new ListNode(-1);
//         // ListNode* temp = head;
//         cout << head->next->val;
//         dummy->next = reverse(temp);
//         // cout << head->next->val;
        
//         int maximum = 0;
//         dummy = dummy->next;
//         ListNode* slow1 = dummy;
//         // cout << slow1->next->next->val;
//         // cout << head->val;
//         ListNode* slow2 = head;
//         // cout << slow2->next->val;
//         // cout << head->next->val;
//         ListNode* fast = head;
//         // cout << fast->next->val;
//         while(fast && fast->next) {
//             int currSum = slow1->val + slow2->val;
//             maximum = max(currSum,maximum);
//             slow1 = slow1->next;
//             slow2 = slow2->next;
//             fast = fast->next->next;   
//         }
        
        
//         return maximum;
        
//     }
    
        int pairSum(ListNode* head) {
        
        ListNode* mid = getMid(head);
        mid->next = reverse(mid->next);
        mid = mid->next;
        ListNode* slow = head;
        int maximum = INT_MIN;
        while(mid) {
            int currSum = slow->val + mid->val;
            maximum = max(currSum,maximum);
            slow = slow->next;
            mid = mid->next; 
        }
        
        
        return maximum;
        
    }
};