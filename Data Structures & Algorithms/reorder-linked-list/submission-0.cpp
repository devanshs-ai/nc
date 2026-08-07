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
    void reorderList(ListNode* head) {
        if(head==nullptr || head->next==nullptr || head->next->next==nullptr){
            return;
        }
        ListNode*fast = head;
        ListNode*slow = head;
        
        while(fast->next && fast->next->next){
            fast = fast->next->next;
            slow = slow->next;
        }

        ListNode*temp = slow->next;
        slow->next = nullptr;
        ListNode*prev = nullptr;

        while(temp){
            ListNode*after = temp->next;
            temp->next = prev;
            prev = temp;
            temp = after;
        }

        ListNode*temp2 = head;
        ListNode*temp3 = prev;
        while(temp3){
            ListNode*first = temp2 -> next;
            ListNode*second = temp3 -> next;

            temp2 -> next = temp3;
            temp3 -> next = first;

            temp2 = first;
            temp3 = second;
        }

    }
};
