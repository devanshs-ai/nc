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
        ListNode dummy(0);          // Create a real node on the stack
        ListNode* merged = &dummy; 
    
        ListNode*head1 = list1;
        ListNode*head2 = list2;

        while(head1!=nullptr && head2!=nullptr){
            if(head1->val>head2->val){
                merged->next = new ListNode(head2->val);
                head2 = head2->next;
            }
            else{
                merged->next = new ListNode(head1->val);
                head1 = head1->next;
            }
            merged = merged->next;
        }

        if(head1){
            merged->next = head1;
        }else if(head2){
            merged->next = head2;
        }

        return dummy.next;
    }
};
