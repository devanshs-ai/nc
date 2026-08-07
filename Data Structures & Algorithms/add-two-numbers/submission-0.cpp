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
    ListNode*reverseLL(ListNode*head){
        ListNode*prev = nullptr;
        while(head){
            ListNode*after = head->next;
            head->next = prev;
            prev = head;
            head = after;
        }
        return prev;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode*temp1 = l1;
        ListNode*temp2 = l2;

        ListNode dummy(0);
        ListNode*res = &dummy;
        int carry = 0;

        while(temp1 && temp2){
           if((temp1->val+temp2->val+carry)<10){
                res->next = new ListNode(temp1->val+temp2->val+carry);
                carry = 0;
            }
            else{
                res->next = new ListNode((temp1->val+temp2->val+carry)%10);
                carry = 1;
            }
            temp1 = temp1->next;
            temp2 = temp2->next;
            res = res->next;
        }

        while(temp1){
            if((temp1->val + carry)<10){
                res->next = new ListNode(temp1->val+carry);
                carry = 0;
            }
            else{
                res->next = new ListNode((temp1->val+carry)%10);
                carry = 1;
            }
            temp1 = temp1->next;
            res = res->next;
        }
        while(temp2){
            if((temp2->val + carry)<10){
                res->next = new ListNode(temp2->val+carry);
                carry = 0;                
            }
            else{
                res->next = new ListNode((temp2->val+carry)%10);
                carry = 1;                
            }
            temp2 = temp2->next;
            res = res->next;
        }

        if(carry == 1){
            res->next = new ListNode(1);
        }

        ListNode*ans = dummy.next;
        return ans;
    }
};