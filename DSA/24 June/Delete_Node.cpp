class Solution {
  public:
    Node* deleteNode(Node* head, int x) {
        if (!head || x <= 0) return head;

        if (x == 1) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return head;
        }

        Node* current = head;
        for (int i = 1; current != nullptr && i < x - 1; ++i) {
            current = current->next;
        }
        if (!current || !current->next) return head;

        Node* temp = current->next;
        current->next = temp->next;
        delete temp;

        return head;
    }
};
