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
    ListNode* rev(ListNode* i) {
        ListNode* i_1 = i->next;
        if(!i_1) return i;
        ListNode* newHead = rev(i->next);
        i_1->next = i;
        return newHead;
    }
    ListNode* reverseList(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* newHead = rev(head->next);
        head->next->next = head;
        head->next = nullptr;
        return newHead;
    }
};
