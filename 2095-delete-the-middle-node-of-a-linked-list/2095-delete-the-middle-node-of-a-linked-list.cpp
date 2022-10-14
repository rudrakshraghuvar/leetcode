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
    ListNode* deleteMiddle(ListNode* head) {
        int n = 0;
        ListNode* temp = head;
            
        while(temp) {
            n++;
            temp = temp -> next;
        }
        
        if(n/2 == 0) return head -> next;
        
        n = (n/2)-1;
        ListNode* curr;
        ListNode* prev = head;

        while(n--)
            prev = prev -> next;

        curr = prev -> next;
        prev -> next = curr -> next;

        return head;
    }
};