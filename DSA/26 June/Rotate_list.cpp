class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || k == 0) return head;
        int len = 1;
        ListNode* tail = head;
        while (tail->next) {
            tail = tail->next;
            len++;
        }
        tail->next = head;
        k = k % len;
        int stepsToNewTail = len - k;
        ListNode* newTail = head;

        for (int i = 1; i < stepsToNewTail; ++i) {
            newTail = newTail->next;
        }
        ListNode* newHead = newTail->next;
        newTail->next = nullptr;

        return newHead;
    }
};
