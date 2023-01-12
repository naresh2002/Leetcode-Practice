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

//  https://leetcode.com/problems/reorder-list/discuss/1744995/Easy-recursive-solution-in-C%2B%2B

class Solution {
public:
    void reorderList(ListNode* head) {
        if(!head || !(head -> next) || !(head -> next -> next)) {
            return;
        }
        
        //last here is actually the 2nd last node of the list
        ListNode *last = head;
        while (last -> next -> next) {
            last = last -> next;
        }
        
		//moving the last node right next to the front node
        last -> next -> next = head -> next;
        head -> next = last -> next;
        last -> next = NULL;
        reorderList(head -> next -> next);
    }
};