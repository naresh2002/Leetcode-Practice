/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* tempA = headA;
        ListNode* tempB = headB;
        
        while (tempA && tempB) {
            tempA = tempA -> next;
            tempB = tempB -> next;
        }
        
        ListNode* newA = headA;
        ListNode* newB = headB;
        while (tempA) {
            newA = newA -> next;
            tempA = tempA -> next;
        }
        while (tempB) {
            newB = newB -> next;
            tempB = tempB -> next;
        }
        while (newA) {
            if(newA == newB) {
                return newA;
            }
            newA = newA -> next;
            newB = newB -> next;
        }
        return NULL;
    }
};