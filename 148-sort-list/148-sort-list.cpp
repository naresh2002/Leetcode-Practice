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
  // Merge Sort :
  
  // Code from - (21. Merge Two Sorted Lists)
  ListNode* merge(ListNode* list1, ListNode* list2) {
    ListNode *ans = new ListNode(-1);
    ListNode *node = ans;
    while (list1 != NULL && list2 != NULL) {
      int a = list1 -> val, b = list2 -> val;
      if (a <= b) {
        ans -> next = list1;
        ans = ans -> next;
        list1 = list1 -> next;
      }
      else {
        ans -> next = list2;
        ans = ans -> next;
        list2 = list2 -> next;
      }
    }
    while (list1 != NULL) {
      ans -> next = list1;
      ans = ans -> next;
      list1 = list1 -> next;
    }
    while (list2 != NULL) {
      ans -> next = list2;
      ans = ans -> next;
      list2 = list2 -> next;
    }
    return node -> next;
  }
  
  ListNode* sortList(ListNode* head) {
    if (!head || !head -> next) {
      return head;
    }
    ListNode *slow = head, *fast = head -> next;
    while (fast && fast -> next) {
      slow = slow -> next;
      fast = fast -> next -> next;
    }
    ListNode *head2 = slow -> next;
    slow -> next = NULL;
    
    return merge(sortList(head), sortList(head2));
  }
};