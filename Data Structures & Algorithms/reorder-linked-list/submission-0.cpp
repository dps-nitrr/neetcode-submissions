/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */class Solution {
public:

    ListNode* reverseList(ListNode* head) {
        ListNode* curr = head;
        ListNode* prev = NULL;

        while (curr) {
            ListNode* forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
        }

        return prev;
    }

    void reorderList(ListNode* head) {

        if (!head || !head->next)
            return;

        // Find end of first half
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Split the list
        ListNode* t2 = slow->next;
        slow->next = NULL;

        // Reverse second half
        t2 = reverseList(t2);

        // First half
        ListNode* t1 = head;

        // Merge alternately
        while (t1 && t2) {

            ListNode* next1 = t1->next;
            ListNode* next2 = t2->next;

            t1->next = t2;
            t2->next = next1;

            t1 = next1;
            t2 = next2;
        }
    }
};