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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode dummy(0);
        dummy.next = head;
        
        ListNode* fast = &dummy;
        ListNode* slow = &dummy;

        if(!head->next){ 
            return 0; 
        }

        while(n>=0){
            fast = fast->next;
            n--;
        }
        while(fast){
            slow = slow->next;
            fast = fast->next;
        }

        ListNode*temp = slow->next->next;
        slow->next = temp;

        return dummy.next;
    }
};
