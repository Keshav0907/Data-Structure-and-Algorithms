// /**
//  * Definition for singly-linked list.
//  * struct ListNode {
//  *     int val;
//  *     ListNode *next;
//  *     ListNode() : val(0), next(nullptr) {}
//  *     ListNode(int x) : val(x), next(nullptr) {}
//  *     ListNode(int x, ListNode *next) : val(x), next(next) {}
//  * };
//  */
// class Solution {
// public:
    
//     int length(ListNode* head) {
        
//         int cnt = 0;
//         ListNode* temp = head;
//         while(temp!=NULL) {
//             cnt++;
//             temp = temp->next;
//         }
        
//         return cnt;
        
//     }
//     ListNode* removeNthFromEnd(ListNode* head, int n) {
        
//         ListNode* temp1 = head;
//         int i = 1;
//         while(i <= n) {
//             temp1 = temp1->next;
//             i++;
//         }
        
//         ListNode* temp2 = head;
//         if(temp1==NULL) {
//             head=head->next;
//             return head;
//         }
//         while(temp1->next!=NULL) {
//             temp2 = temp2->next;
//             temp1 = temp1->next;
//         }
        
//         temp2->next = temp2->next->next;
//         return head;
        
//         // int l = length(head);
//         // int k = l - n;
        
//         // if(k==0) {
//         //     head=head->next;
//         //     return head;
//         // }
  
//         // ListNode* temp = head;
//         // int i=1;
//         // while(i < k) {
//         //     temp = temp->next;
//         //     i++;
//         // }
//         // cout << temp->val;
//         // temp->next = temp->next->next;
//         // return head;
//     }
// };

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode * start = new ListNode();
        start -> next = head;
        ListNode* fast = start;
        ListNode* slow = start;     

        for(int i = 1; i <= n; ++i)
            fast = fast->next;
    
        while(fast->next != NULL)
        {
            fast = fast->next;
            slow = slow->next;
        }
        
        slow->next = slow->next->next;
        
        return start->next;
    }
};