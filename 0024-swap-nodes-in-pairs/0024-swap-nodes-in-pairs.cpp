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
    ListNode* swapPairs(ListNode* head) {
        if (!head || !head -> next) {
            return head;
        }
        ListNode* ans = new ListNode(-1);
        ListNode* node = ans;
        
        while (head && head -> next) {
            node -> next = head -> next;
            node = node -> next;
            ListNode* temp = NULL;
            if (node -> next) {
                temp = node -> next;
            }
            node -> next = head;
            node = node -> next;
            head = temp;
        }
        if (head) {
            node -> next = head;
        }
        else {
            node -> next = NULL;
        }
        return ans -> next;
    }
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
//     ListNode* swapPairs(ListNode* head) {
//         if (!head) {
//             return head;
//         }
//         ListNode *node = new ListNode(-1);
//         ListNode *ans = node;

//         while (head && head -> next) {
//             node -> next = head -> next;
//             node = node -> next;
//             ListNode *temp = NULL;
//             if (node -> next){
//                 temp = node -> next;
//             }
//             node -> next = head;
//             node = node -> next;
//             head = temp;
//         }
//         if (head) {
//             node -> next = head;
//             (node -> next) -> next = NULL;
//         }
//         else {
//             node -> next = NULL;
//         }
//         return ans -> next;
//     }
};