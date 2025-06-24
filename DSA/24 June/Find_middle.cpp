class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        int count = 0;
        ListNode* temp = head;
        while (temp) {
            count++;
            temp = temp->next;
        }

        int mid = count / 2;
        temp = head;
        while (mid--) {
            temp = temp->next;
        }

        return temp;
    }
};
