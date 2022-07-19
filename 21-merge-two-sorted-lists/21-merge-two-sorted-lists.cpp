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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *ptr1 = list1;
        ListNode *ptr2 = list2;
        ListNode *ans = new ListNode(-1);
        ListNode *list = ans;
        while (ptr1 && ptr2) {
            if(ptr1 -> val <= ptr2 -> val) {
                list -> next = ptr1;
                ptr1 = ptr1 -> next;
            }
            else {
                list -> next = ptr2;
                ptr2 = ptr2 -> next;
            }
            list = list -> next;
        }
        while (ptr1) {
            list -> next = ptr1;
            ptr1 = ptr1 -> next;
            list = list -> next;
        }
        while (ptr2) {
            list -> next = ptr2;
            ptr2 = ptr2 -> next;
            list = list -> next;
        }
        return ans -> next;
    }
};