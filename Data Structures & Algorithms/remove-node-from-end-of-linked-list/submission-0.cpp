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
    int getLength(ListNode* head) {
        ListNode* temp = head;
        int length = 0;
        while(temp) {
            temp = temp->next;
            length++;
        }
        return length;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int length = getLength(head);
        if(length == n) return head->next;
        int toBeDeleted = length - n; // 2
        int index = 0;
        ListNode* temp = head;
        while(index < toBeDeleted - 1) {
            temp = temp->next;
            index++;
        }
        temp->next = temp->next->next;
        return head;
    }
};
