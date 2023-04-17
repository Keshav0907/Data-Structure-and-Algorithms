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
    
//     ListNode* merge(ListNode* a,ListNode* b) {
        
//         if(a==NULL) {
//             return b;
//         } else if(b==NULL) {
//             return a;
//         }
        
//         ListNode* temp;
        
//         if(a->val <= b->val) {
//             temp = a;
//             temp->next = merge(a->next,b);
//         } else {
//             temp = b;
//             temp->next = merge(a,b->next);
//         }
        
//          return temp;
        
//     }
    
      ListNode* merge(ListNode* a,ListNode* b) {
        
        ListNode* dummy = new ListNode(-1);
        ListNode* curr = dummy;
        while(a && b) {
            
            if(a->val <= b->val) {
                dummy->next = a;
                a = a->next;
            } else {
                dummy->next = b;
                b = b->next;
            }
            
            dummy = dummy->next;
            
        }
        
        if(a) dummy->next = a;
        if(b) dummy->next = b;
        
        return curr->next;
      }
    
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


// class Solution {
// public:
//     ListNode* sortList(ListNode* head) {
//         if (!head || !head->next)
//             return head;
//         ListNode* mid = getMid(head);
//         ListNode *right = mid->next;
//         mid->next = NULL;
//         ListNode* left = sortList(head);
//         right = sortList(mid);
//         return merge(left, right);
//     }

//     ListNode* merge(ListNode* list1, ListNode* list2) {
//         ListNode dummyHead(0);
//         ListNode* ptr = &dummyHead;
//         while (list1 && list2) {
//             if (list1->val < list2->val) {
//                 ptr->next = list1;
//                 list1 = list1->next;
//             } else {
//                 ptr->next = list2;
//                 list2 = list2->next;
//             }
//             ptr = ptr->next;
//         }
//         if(list1) ptr->next = list1;
//         else ptr->next = list2;

//         return dummyHead.next;
//     }

//     // ListNode* getMid(ListNode* head) {
//     //     ListNode* midPrev = nullptr;
//     //     while (head && head->next) {
//     //         midPrev = (midPrev == nullptr) ? head : midPrev->next;
//     //         head = head->next->next;
//     //     }
//     //     ListNode* mid = midPrev->next;
//     //     midPrev->next = nullptr;
//     //     return mid;
//     // }
    
//         ListNode* getMid(ListNode* head) {
        
//         ListNode* slow = head;
//         ListNode* fast = head->next;
        
//         while(fast && fast->next) {
//             slow = slow->next;
//             fast = fast->next;
//         }
        
//         return slow;
        
        
//     }
// };
