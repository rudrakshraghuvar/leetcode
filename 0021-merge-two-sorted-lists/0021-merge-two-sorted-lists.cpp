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
        ListNode* head = new ListNode(200);
        ListNode* h = head;
        while(list2 && list1) {
            if(list2->val >= list1->val) {
                h->next = list1;
                list1 = list1->next;
                h = h->next;
            }
            else {
                h->next = list2;
                list2 = list2->next;
                h = h->next;
            }
        }
        while(list1) {
            h->next = list1;
            list1 = list1->next;
            h = h->next;
        }
        while(list2) {
            h->next = list2;
            list2 = list2->next;
            h = h->next;
        }
        return head->next;
    }
};