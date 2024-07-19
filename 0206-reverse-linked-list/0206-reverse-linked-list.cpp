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
    ListNode *node;
    void reverse(ListNode *head) {
        if (!head) {
            return;
        }
        reverse(head -> next);
        node -> next = head;
        node = node -> next;
        head -> next = NULL;
    }
    
    ListNode* reverseList(ListNode* head) {
        node = new ListNode(-1);
        ListNode* ans = node;
        reverse(head);
        return ans -> next;
    }
};