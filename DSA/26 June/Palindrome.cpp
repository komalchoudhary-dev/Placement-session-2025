class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (!head || !head->next) return true;

        ListNode* slow = head;
        ListNode* fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* prev = NULL;
        ListNode* curr = slow;
        while (curr) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        ListNode* fHalf = head;
        ListNode* sHalf = prev;
        while (sHalf) {
            if (fHalf->val != sHalf->val)
                return false;
            fHalf = fHalf->next;
            sHalf = sHalf->next;
        }

        return true;
    }
};
