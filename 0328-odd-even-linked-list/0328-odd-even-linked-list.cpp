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
    ListNode* oddEvenList(ListNode* head) {
        if (!head || !head -> next) {
            return head;
        }
        ListNode *temp1 = head;
        ListNode *temp2 = head -> next;
        ListNode *temp3 = head -> next;
        // ListNode *temp11 = temp1;
        // ListNode *temp22 = temp2;
        
        while (temp2 -> next) {
            temp1 -> next = temp2 -> next;
            temp1 = temp1 -> next;
            if (temp2 -> next -> next) {
                temp2 -> next = temp2 -> next -> next;
                temp2 = temp2 -> next;
            }
            else {
                break;
            }
        }
        temp1 -> next = temp3;
        temp2 -> next = NULL;
        return head;
    }
};