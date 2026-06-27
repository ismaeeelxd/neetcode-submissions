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
    ListNode* rev_helper(ListNode* i) {
        ListNode* i_1 = i->next;
        if (!i_1) return i;
        ListNode* newHead = rev_helper(i_1);
        i_1->next = i;
        return newHead;
    }

    ListNode* reverseList(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode* newHead = rev_helper(head->next);
        head->next->next = head;
        head->next = NULL;
        return newHead;
    }
    int getListLength(ListNode* head) {
        int length = 0;
        ListNode* temp = head;
        while (temp) {
            length++;
            temp = temp->next;
        }
        return length;
    }

    ListNode* getMidNode(ListNode* head, int length) {
        int mid = ceil(length / 2.0);
        int index = 0;
        ListNode* midNode = head;
        while (index != mid - 1) {
            midNode = midNode->next;
            index++;
        }
        ListNode* temp = midNode->next;
        midNode->next = nullptr;
        return temp;
    }
    void reorderList(ListNode* head) {
        int length = getListLength(head);
        if (length == 0 || length == 1 || length == 2) {
            return;
        }
        ListNode* midNode = getMidNode(head, length);
        ListNode* newHead = reverseList(midNode);
        int index = 1;
        ListNode* l1 = head;
        ListNode* l2 = newHead;

        while (index <= length) {
            bool isEven = index++ % 2 == 0;
            if (!isEven) {
                ListNode* templ1 = l1->next;  
                l1->next = l2;                
                l1 = templ1;                  
            } else {
                ListNode* templ2 = l2->next;  
                l2->next = l1;                
                l2 = templ2;                  
            }
        }

        return;
    }
};
