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
    ListNode* reverse(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = NULL;
        
        while(head != NULL) {
            prev = curr;
            curr = head;
            head = head->next;
            curr->next = prev;
        }
        return curr;
    }
    
    ListNode* removeNodes(ListNode* head) {
        ListNode* temp = reverse(head);
        ListNode* prev;
        ListNode* newHead = temp;
        int mx = INT_MIN;
        
        while(temp) {
            mx = max(mx, temp->val);
            if(mx == temp->val) {
                prev = temp;
                temp = temp->next;
            }
            else if(mx > temp->val) {
                prev->next = temp->next;
                temp = temp->next;
            }
        }
        
        return reverse(newHead);
    }
};