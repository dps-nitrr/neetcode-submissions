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
        ListNode* temp=head;
        int len=0;
        while(temp){
            temp=temp->next;
            len++;
        }
        if(len==n)return head->next;
        int rem=len-n-1;
        temp=head;
        while(rem){
            rem--;
            temp=temp->next;
        }
       if(temp->next) temp->next=temp->next->next;
        return head;
    }
};
